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

	UPROPERTY(EditAnywhere)
		int score = 0;
public:
	FORCEINLINE void AddScore(int _value)
	{
		score += _value; 
		UE_LOG(LogTemp, Warning, TEXT("%d"), score);
	}
	FORCEINLINE int GetScore() const { return score; }
};
