// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ScoreManager.generated.h"

/**
 * 
 */
UCLASS()
class MARIOCORR_API UScoreManager : public UObject
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddScore, int, _score);
	FOnAddScore onAddScore;
	UPROPERTY(EditAnywhere)
		int score = 0;
public:
	FORCEINLINE FOnAddScore& OnAddScore() { return onAddScore; }
	FORCEINLINE void AddScore(int _value)
	{
		score += _value; 
		onAddScore.Broadcast(score);
	}
	FORCEINLINE int GetScore() const { return score; }
	void ResetScore();
};
