// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationSettings.generated.h"

/**
 * 
 */
UCLASS()
class PNJCAMERAPROJECT_API UConversationSettings : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta =(UIMin = 100, ClampMin = 100))
	float distance = 500;
	UPROPERTY(EditAnywhere, Category="Camera Settings")
	float angle = 45;
	UPROPERTY(EditAnywhere, Category="Camera Settings")
	float cameraHeight = 0;

public:
	FORCEINLINE float Distance() const { return distance; }
	FORCEINLINE float Angle() const { return angle; }
	FORCEINLINE float CameraHeight() const { return cameraHeight; }
};
