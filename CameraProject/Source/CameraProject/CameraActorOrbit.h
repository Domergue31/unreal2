// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraActorMovement.h"
#include "CameraActorOrbit.generated.h"

/**
 * 
 */
UCLASS()
class CAMERAPROJECT_API ACameraActorOrbit : public ACameraActorMovement
{
	GENERATED_BODY()
	
	float angle = 0;

public:
	ACameraActorOrbit();
	virtual FVector GetFinalLocation() override
	{
		return GetTargetLocation() + RotationPoint();
	}

protected:
	virtual void Tick(float DeltaTime) override;

	virtual void UpdateCameraPosition() override;
	virtual void DrawDebug() override;

	FVector RotationPoint();
	float ComputeAngle();
	float EaseInOutBounce(float _x);
	float EaseOutElastic(float _x);
	float EaseOutBounce(float& _x);
};
