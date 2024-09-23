// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/UserDefinedEnum.h" //Engine
#include "SLTest.generated.h"

UCLASS()
class OCTREESUBLEVELS_API ASLTest : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="CreateBlueprint", meta = (BlueprintBaseOnly))
	TSubclassOf<UObject> blueprintParentClass = nullptr;
	UPROPERTY(EditAnywhere, Category = "CreateBlueprint")
	FString blueprintPath;

	UPROPERTY(EditAnywhere, Category="CreateAsset")
	TObjectPtr<UClass> assetParentClass = nullptr;
	UPROPERTY(EditAnywhere, Category = "CreateAsset")
	FString assetPath;


public:	
	ASLTest();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(CallInEditor, Category = "CreateBlueprint") void CreateBlueprintTest();

	UFUNCTION(CallInEditor, Category = "CreateAsset") void CreateAssetTest();

};
