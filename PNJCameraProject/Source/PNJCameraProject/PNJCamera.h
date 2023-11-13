// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "PNJCamera.generated.h"

/**
 * 
 */
UCLASS()
class PNJCAMERAPROJECT_API APNJCamera : public ACameraActor
{
	GENERATED_BODY()
	
public:
	APNJCamera();
	UFUNCTION() virtual FVector FinalPosition(class APNJActor* _pnj);
protected:
	FVector GetTrigoPosition(float _distance, float _angle);
};
