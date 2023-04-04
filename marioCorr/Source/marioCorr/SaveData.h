// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SaveData.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API USaveData : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
		bool savePowerUp = false;
	UPROPERTY(VisibleAnywhere)
		int saveCoins = 0;
	UPROPERTY(VisibleAnywhere)
		int saveScore = 0;

public:
	void SavedCharacter(class AMarioCharacter* _char);
	void LoadCharacter(class AMarioCharacter* _char);
};
