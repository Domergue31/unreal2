// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameProgress.generated.h"

/**
 * 
 */
UCLASS()
class SAVEEX_API UGameProgress : public USaveGame
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere)
		int playerLife = 0;
public:
	FORCEINLINE void SetSaveLife(const int& _life) { playerLife = _life; }
	FORCEINLINE int GetSaveLife() const { return playerLife; }
};
