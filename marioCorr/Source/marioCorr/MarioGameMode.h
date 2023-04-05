// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CoinManager.h"
#include "ScoreManager.h"
#include "MarioGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API AMarioGameMode : public AGameModeBase
{
	GENERATED_BODY()

	/*UPROPERTY(EditAnywhere)
		TObjectPtr<UCoinManager> coins = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UScoreManager> score = nullptr;

public:
	FORCEINLINE TObjectPtr<UCoinManager> GetCoins() { return coins; }
	FORCEINLINE TObjectPtr<UScoreManager> GetScore() { return score; }*/
protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
