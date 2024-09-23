// Fill out your copyright notice in the Description page of Project Settings.


#include "SL_CreateBlueprint.h"
#include "AssetRegistry/AssetRegistryModule.h" // AssetRegistry
#include "KismetCompilerModule.h" // KismetCompiler (Editor Only)
#include "Kismet2/KismetEditorUtilities.h" // UnrealEd (Editor Only)

UBlueprint* USL_CreateBlueprint::CreateBlueprint(const FString& _blueprintPath, TSubclassOf<UObject> _parentClass, bool& _bOutSuccess, FString& _outInfoMessage)
{
	//Make sure an Asset doesn't already exist  with that path
	if (StaticLoadObject(UObject::StaticClass(), nullptr, *_blueprintPath) != nullptr)
	{
		_bOutSuccess = false;
		_outInfoMessage = FString::Printf(TEXT("Create Blueptint Failed - An asset already exist at that location. '%s'"), *_blueprintPath);
		return nullptr;
	}

	//Make sure the parent class is valid 
	if (!FKismetEditorUtilities::CanCreateBlueprintOfClass(_parentClass))
	{
		_bOutSuccess = false;
		_outInfoMessage = FString::Printf(TEXT("Create Blueptint Failed - Parent class is not blueprintable. '%s'"), *_blueprintPath);
		return nullptr;
	}

	//Create asset package
	UPackage* _package = CreatePackage(*_blueprintPath);
	if (!_package)
	{
		_bOutSuccess = false;
		_outInfoMessage = FString::Printf(TEXT("Create Blueptint Failed - Failed to create the asset package. Make sur the asset path is valid. '%s'"), *_blueprintPath);
		return nullptr;
	}

	//Find the blueprint Class to Create
	UClass* _bPClass = nullptr;
	UClass* _bPGenClass = nullptr;
	FModuleManager::LoadModuleChecked<IKismetCompilerInterface>("KismetCompiler").GetBlueprintTypesForClass(_parentClass, _bPClass, _bPGenClass);

	//Create asset
	UBlueprint* _blueprint = FKismetEditorUtilities::CreateBlueprint(_parentClass, _package, *FPaths::GetBaseFilename(_blueprintPath), BPTYPE_Normal, _bPClass, _bPGenClass);


	//Register asset
	FAssetRegistryModule::AssetCreated(_blueprint);
	_blueprint->MarkPackageDirty();


	//UWorld::CreateWorld(EWorldType::Game, true, "NewWorld_Level", _package);

	return _blueprint;
}
