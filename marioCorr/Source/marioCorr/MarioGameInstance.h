// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoinManager.h"
#include "ScoreManager.h"
#include "MarioTimerManager.h"
#include "MarioGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UMarioGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
		UPROPERTY(EditAnywhere)
		TObjectPtr<UCoinManager> coins = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UScoreManager> score = nullptr;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UMarioTimerManager> timerRef = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UMarioTimerManager> timer = nullptr;

public:
	FORCEINLINE TObjectPtr<UCoinManager> GetCoins() { return coins; }
	FORCEINLINE TObjectPtr<UScoreManager> GetScore() { return score; }
	FORCEINLINE TObjectPtr<UMarioTimerManager> GetTimer() { return timer; }
protected:
	void Init() override;
};
