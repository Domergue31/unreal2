// Fill out your copyright notice in the Description page of Project Settings.


#include "SLTest.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Engine/LevelStreamingDynamic.h>
#include <Kismet2/KismetEditorUtilities.h>
#include <kismet/KismetSystemLibrary.h>
#include <AssetRegistry/AssetRegistryModule.h>
#include "Engine/Blueprint.h"
#include "SL_CreateBlueprint.h"
#include "SL_CreateAsset.h"

ASLTest::ASLTest()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASLTest::BeginPlay()
{
	Super::BeginPlay();
	//UKismetSystemLibrary::PrintString(this, "Begin Play", true, false, FColor::Blue, 5);
	TArray<ULevelStreaming*> _streamingLevels = GetWorld()->GetStreamingLevels();
	for (ULevelStreaming* _streamingLevel : _streamingLevels)
	{
		UKismetSystemLibrary::PrintString(this, _streamingLevel->GetWorldAssetPackageName(), true, false, FColor::Blue, 5);
	}
	//FName BluePrintName = FName("SLTest2_BP");
	//FString AssetPath = "Game/Blueprints/Test" "/" + BluePrintName.ToString();
	//UPackage* BluePrintPackage = CreatePackage(*AssetPath);
	//
	//
	//FKismetEditorUtilities::CreateBlueprint(ASLTest::StaticClass(), BluePrintPackage, BluePrintName, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass());
	//ULevel* _newLevel = NewObject<ULevel>();
	//GetWorld()->AddLevel(_newLevel);
}

void ASLTest::CreateBlueprintTest()
{
	bool _result = false;
	FString _message = "";
	USL_CreateBlueprint::CreateBlueprint(blueprintPath, blueprintParentClass, _result, _message);

	UKismetSystemLibrary::PrintString(this, _message, true, false, FColor::Red, 5);
}

void ASLTest::CreateAssetTest()
{
	bool _result = false;
	FString _message = "";
	USL_CreateAsset::CreateAsset(assetPath, assetParentClass, nullptr, _result, _message);

	UKismetSystemLibrary::PrintString(this, _message, true, false, FColor::Red, 5);
}
