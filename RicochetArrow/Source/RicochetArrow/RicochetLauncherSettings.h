// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "RicochetArrowActor.h"
#include "RicochetLauncherSettings.generated.h"

/**
 * 
 */
UCLASS()
class RICOCHETARROW_API URicochetLauncherSettings : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Shoot")
	TSubclassOf<ARicochetArrowActor> ricochetArrowRef = nullptr;
	UPROPERTY(EditAnywhere, Category = "Shoot", meta = (UIMin = 1, ClampMin = 1))
	int hitNumber = 1;
	UPROPERTY(EditAnywhere, Category = "Shoot")
	TArray<TEnumAsByte<EObjectTypeQuery>> objectsType;
	UPROPERTY(EditAnywhere, Category = "Shoot", meta = (UIMin = 100, ClampMin = 100))
	float range = 100;

public:
	FORCEINLINE TSubclassOf<ARicochetArrowActor> RicochetArrowRef() const { return ricochetArrowRef; }
	FORCEINLINE int HitNumber() const { return hitNumber; }
	FORCEINLINE TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsType() { return objectsType; }
	FORCEINLINE float Range() const { return range; }
};
