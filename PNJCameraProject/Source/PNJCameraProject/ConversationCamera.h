// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PNJCamera.h"
#include "Camera/CameraActor.h"
#include "ConversationCamera.generated.h"

/**
 * 
 */
UCLASS()
class PNJCAMERAPROJECT_API AConversationCamera : public APNJCamera
{
	GENERATED_BODY()
	

public:
	AConversationCamera();
	virtual FVector FinalPosition(APNJActor* _pnj) override;

};
