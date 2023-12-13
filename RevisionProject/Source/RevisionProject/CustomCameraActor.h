// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "CustomCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class REVISIONPROJECT_API ACustomCameraActor : public ACameraActor
{
	GENERATED_BODY()


public:
	ACustomCameraActor();
protected:
	virtual void Tick(float DeltaTime) override;


	bool ShouldTickIfViewportsOnly() const override;
};
