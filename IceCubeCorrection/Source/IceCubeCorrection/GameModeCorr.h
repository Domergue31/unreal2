// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GridActor.h"
#include "GameModeCorr.generated.h"

/**
 * 
 */
UCLASS()
class ICECUBECORRECTION_API AGameModeCorr : public AGameModeBase
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TSoftObjectPtr<AGridActor> grid = nullptr;

public:
	FORCEINLINE TObjectPtr<AGridActor> GetGrid() const
	{
		return grid.Get();
	}
};
