// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraSettings.h"
#include "CameraSettingsFollow.generated.h"

/**
 * 
 */
UCLASS()
class CAMERAPROJECT_API UCameraSettingsFollow : public UCameraSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EMovementType> movementType = EMovementType::Lerp;
	UPROPERTY(EditAnywhere)
	TEnumAsByte<EOffsetType> offsetType = EOffsetType::Local;
	UPROPERTY(EditAnywhere, meta = (UMin = -2000, ClampMin = -2000, UMax = 2000, ClampMax = 2000))
	float offsetX;
	UPROPERTY(EditAnywhere, meta = (UMin = -2000, ClampMin = -2000, UMax = 2000, ClampMax = 2000))
	float offsetY;
	UPROPERTY(EditAnywhere, meta = (UMin = -2000, ClampMin = -2000, UMax = 2000, ClampMax = 2000))
	float offsetZ;
	UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMin = 0, UMax = 1000, ClampMax = 1000))
	float cameraSpeed;


public:
	FORCEINLINE EMovementType GetMovementType() const { return movementType; }
	FORCEINLINE EOffsetType GetOffsetType() const { return offsetType; }
	FORCEINLINE FVector GetOffset() const { return FVector(offsetX, offsetY, offsetZ); }
	FORCEINLINE float GetCameraSpeed() const { return cameraSpeed; }


};
