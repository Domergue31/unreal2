// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MobSettings.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API UMobSettings : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int life = 1;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClamMin = 1))
		float speed = 100;

public:
	FORCEINLINE int GetLife() const { return life; }
	FORCEINLINE float Speed() const { return speed; }
};
