// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PathhManager.h"
#include "PawnSwitcher.h"
#include "PathCorrGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PATHCORR_API APathCorrGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY()
		TObjectPtr<UPathhManager> pathManager = nullptr;
	UPROPERTY()
		TObjectPtr<APawnSwitcher> pawnSwitcher = nullptr;
public:
	FORCEINLINE TObjectPtr<UPathhManager> GetPathManager() { return pathManager; }
	FORCEINLINE TObjectPtr<APawnSwitcher> GetPawnManager() { return pawnSwitcher; }
private:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
};
