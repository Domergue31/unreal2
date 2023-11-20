// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CameraManager.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
class UCameraManager_C;
UCLASS()
class CCC_2023_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Manager")
	TSubclassOf<UCameraManager_C> cameraManagerRef = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (EditInLine, AllowPrivateAccess))
	TObjectPtr<UCameraManager_C> currentCameraManagerInstance = nullptr;
	
	 virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
public:
	FORCEINLINE TObjectPtr<UCameraManager_C> CameraManager() { return currentCameraManagerInstance; }
};
