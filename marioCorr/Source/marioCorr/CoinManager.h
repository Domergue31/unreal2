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
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddCoin, int, _score);
	FOnAddCoin onAddCoin;
	UPROPERTY(EditAnywhere)
		int coins = 0;
public:
	FORCEINLINE FOnAddCoin& OnAddCoin() { return onAddCoin; }
	FORCEINLINE void AddCoins(int _value) 
	{
		coins += _value; 
		onAddCoin.Broadcast(coins);
	}
	FORCEINLINE int GetCoins() const { return coins; }
	void ResetCoins();
};
