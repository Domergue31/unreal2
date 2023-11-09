// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraSettings.h"
#include "CameraSettingsOrbit.generated.h"

/**
 * 
 */
UCLASS()
class CAMERAPROJECT_API UCameraSettingsOrbit : public UCameraSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
	float radius = 200;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
	float duration = 1;

public:
	FORCEINLINE float GetRadius() const { return radius; }
	FORCEINLINE float GetDuration() const { return duration; }
};
