// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StreamingSourceManager.h"
#include "MinimapTestGameMode.generated.h"

UCLASS(minimalapi)
class AMinimapTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<AStreamingSourceManager> streamingManagerRef = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<AStreamingSourceManager> streamingManager = nullptr;


public:
	FORCEINLINE TObjectPtr<AStreamingSourceManager> GetStreamingSourceManager() const { return streamingManager; }
	AMinimapTestGameMode();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;


	void LoadLevel(const FName& _nameLevel);
	void UnloadLevel(const FName& _nameLevel);
};



