// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SightSystemAsset.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API USightSystemAsset : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMIn = 0, UMax = 360, ClampMax = 360)) int sightAngle = 90;
	UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMIn = 0)) int range = 500;
	UPROPERTY(EditAnywhere, meta = (UMin = 1, ClampMIn = 1)) int definition = 1;
	UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> layers;
	UPROPERTY(EditAnywhere) TArray<TEnumAsByte<EObjectTypeQuery>> obstacleLayers;
	UPROPERTY(EditAnywhere) float sightHeight = 0;

public:
	FORCEINLINE int GetSightAngle() const { return sightAngle; }
	FORCEINLINE int GetRange() const { return range; }
	FORCEINLINE int GetDefinition() const { return definition; }
	FORCEINLINE TArray<TEnumAsByte<EObjectTypeQuery>> GetLayers() const { return layers; }
	FORCEINLINE TArray<TEnumAsByte<EObjectTypeQuery>> GetObstacleLayers() const { return obstacleLayers; }
	FORCEINLINE float GetSightHeight() const { return sightHeight; }
};
