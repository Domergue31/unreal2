// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoinManager.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UCoinManager : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		int coins = 0;
public:
	FORCEINLINE void AddCoins(int _value) { coins += _value; }
	FORCEINLINE int GetCoins() const { return coins; }
};
