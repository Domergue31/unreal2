// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SpawnerSettings.generated.h"

/**
 * 
 */
UCLASS()
class PATHCORR_API USpawnerSettings : public UDataAsset
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> spawnItem = nullptr;
	UPROPERTY(EditAnywhere, meta = (UIMin = .1f, ClampMin = .1f))
		float timer = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = .1f, ClampMin = .1f))
		bool clampSpawnLimit = false;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1, EditCondition = clampSpawnLimit))
		int maxSpawnSize = 10;
public:
	FORCEINLINE float GetMaxTimer() { return timer; }
	FORCEINLINE int GetMaxSpawnSize() { return maxSpawnSize; }
	FORCEINLINE bool ClampSpawnLimit() { return clampSpawnLimit; }
	FORCEINLINE TSubclassOf<AActor> GetSpawnItem() { return spawnItem; }
};
