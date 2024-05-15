// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "CustomWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class MINIMAPTEST_API ACustomWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="StreamingManagerSubsystem", meta = (UMin = 0, ClampMin = 0))
	float baseHeight = 5000.0f;
	UPROPERTY(EditAnywhere, Category="StreamingManagerSubsystem", meta = (UMin = 0, ClampMin = 0))
	float depthScale = 0.8f;

	UPROPERTY(EditAnywhere, Category = "SubLevelsData")
	FString temp_currentWeather = "";
	UPROPERTY(EditAnywhere, Category = "SubLevelsData")
	TMap<FString, UWorld*> subLevels;


public:
	float GetBaseHeight() const { return baseHeight; }
	float GetDepthScale() const { return depthScale; }

protected:
	virtual void BeginPlay() override;

};
