// Fill out your copyright notice in the Description page of Project Settings.


#include "SL_CreateAsset.h"

#include "AssetToolsModule.h" //AssetTools

#include "LevelSequence.h" //LevelSequence
#include "NiagaraSystem.h" //Niagara
#include "Sound/SoundCue.h" // Engine
#include "Engine/UserDefinedEnum.h" //Engine
#include "Engine/UserDefinedStruct.h" //Engine

#include "Factories/WorldFactory.h" //UnrealEd (Editor Only)
#include "Factories/MaterialFactoryNew.h" //UnrealEd (Editor Only)


//all factories:
// https://docs.unrealengine.com/5.1/en-US/API/Editor/UnrealEd/Factories/UFactory/

UObject* USL_CreateAsset::CreateAsset(const FString& _assetPath, UClass* _assetClass, UFactory* _assetFactory, bool& _bOutResult, FString& _outInfoMessage)
{
	IAssetTools& _assetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

	UFactory* _factory = _assetFactory;
	if (_factory == nullptr)
	{
		for (UFactory* _fac : _assetTools.GetNewAssetFactories())
		{
			if (_fac->SupportedClass == _assetClass)
			{
				_factory = _fac;
				break;
			}
		}
	}

	if (_factory == nullptr)
	{
		_bOutResult = false;
		_outInfoMessage = FString::Printf(TEXT("Create Asset Failed - Was not  able to find a factory for AssetClass. '%s'"), *_assetClass->GetName());
		return nullptr;
	}

	if (_factory->SupportedClass != _assetClass)
	{
		_bOutResult = false;
		_outInfoMessage = FString::Printf(TEXT("Create Asset Failed - Factory cannot create desired AssetClass. '%s'"), *_assetClass->GetName());
		return nullptr;
	}

	if (UObject * _asset = _assetTools.CreateAsset(FPaths::GetBaseFilename(_assetPath), FPaths::GetPath(_assetPath), _assetClass, _factory))
	{
		_bOutResult = true;
		_outInfoMessage = FString::Printf(TEXT("Create Asset Succeeded - '%s'"), *_assetPath);
		return _asset;
	}

	_bOutResult = false;
	_outInfoMessage = FString::Printf(TEXT("Create Asset Failed - Either the path is invalid or the asset already exist. '%s'"), *_assetPath);
	return nullptr;
}

UWorld* USL_CreateAsset::CreateWorldAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UWorldFactory* _factory = NewObject<UWorldFactory>();
	_factory->WorldType = EWorldType::Game;

	UObject* _asset = CreateAsset(_assetPath, UWorld::StaticClass(), _factory, _bOutResult, _outInfoMessage);

	return Cast<UWorld>(_asset);
}

UMaterial* USL_CreateAsset::CreateMaterialAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UMaterialFactoryNew* _factory = NewObject<UMaterialFactoryNew>();
	_factory->InitialTexture = nullptr;

	UObject* _asset = CreateAsset(_assetPath, UMaterial::StaticClass(), _factory, _bOutResult, _outInfoMessage);

	return Cast<UMaterial>(_asset);
}

UNiagaraSystem* USL_CreateAsset::CreateNiagaraSystemAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UObject* _asset = CreateAsset(_assetPath, UNiagaraSystem::StaticClass(), nullptr, _bOutResult, _outInfoMessage);

	return Cast<UNiagaraSystem>(_asset);
}

ULevelSequence* USL_CreateAsset::CreateLevelSequenceAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UObject* _asset = CreateAsset(_assetPath, ULevelSequence::StaticClass(), nullptr, _bOutResult, _outInfoMessage);

	return Cast<ULevelSequence>(_asset);
}

UUserDefinedEnum* USL_CreateAsset::CreateEnumAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UObject* _asset = CreateAsset(_assetPath, UUserDefinedEnum::StaticClass(), nullptr, _bOutResult, _outInfoMessage);

	return Cast<UUserDefinedEnum>(_asset);
}

UUserDefinedStruct* USL_CreateAsset::CreateStructAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UObject* _asset = CreateAsset(_assetPath, UUserDefinedStruct::StaticClass(), nullptr, _bOutResult, _outInfoMessage);

	return Cast<UUserDefinedStruct>(_asset);
}

USoundCue* USL_CreateAsset::CreateSoundCueAsset(const FString& _assetPath, bool& _bOutResult, FString& _outInfoMessage)
{
	UObject* _asset = CreateAsset(_assetPath, USoundCue::StaticClass(), nullptr, _bOutResult, _outInfoMessage);

	return Cast<USoundCue>(_asset);
}
