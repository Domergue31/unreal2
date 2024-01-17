// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PathManager.h"
#include "WaypointManager.h"
#include "GuardGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API AGuardGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TSubclassOf<UPathManager> pathManagerRef = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<UPathManager> pathManager = nullptr;
	UPROPERTY(EditAnywhere) TSubclassOf<UWaypointManager> waypointManagerRef = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<UWaypointManager> waypointManager = nullptr;


	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

public:
	FORCEINLINE TObjectPtr<UPathManager> GetPathManager() { return pathManager; }
	FORCEINLINE TObjectPtr<UWaypointManager> GetWaypointManager() { return waypointManager; }
};
