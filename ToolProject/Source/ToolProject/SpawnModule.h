// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SpawnModule.generated.h"

/**
 * 
 */
UCLASS(ABSTRACT)
class TOOLPROJECT_API USpawnModule : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Spawn module")
	FString moduleName = "Module";
	UPROPERTY(EditAnywhere, Category = "Spawn module")
	bool moduleEnable = false;

public:
	FORCEINLINE void ModuleEnable(const bool& _value) { moduleEnable = _value; }
	FORCEINLINE bool GetModuleEnable() const { return moduleEnable; }
	FORCEINLINE FString GetModuleName() const { return moduleName; }
	virtual void DrawDebug(UWorld* _world, const FVector& _origin);
	virtual TArray<AActor*> Spawn(class ASpawnTool* _tool);

	
};
