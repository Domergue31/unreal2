// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WorldPartitionGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WORLDPARTITIONTEST_API AWorldPartitionGameMode : public AGameModeBase
{
	GENERATED_BODY()




private:
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
