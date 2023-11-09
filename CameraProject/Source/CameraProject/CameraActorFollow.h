// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraActorMovement.h"
#include "CameraSettingsFollow.h"
#include "CameraActorFollow.generated.h"

/**
 * 
 */
UCLASS()
class CAMERAPROJECT_API ACameraActorFollow : public ACameraActorMovement
{
	GENERATED_BODY()
	


public:
	ACameraActorFollow();
	virtual FVector GetOffset() override
	{
		TObjectPtr<UCameraSettingsFollow> _set = Cast<UCameraSettingsFollow>(cameraSettings);
		if (_set->GetOffsetType() == EOffsetType::Local)
			return GetLocalOffset(_set->GetOffset().X, _set->GetOffset().Y, _set->GetOffset().Z);
		else
			return FVector(_set->GetOffset().X, _set->GetOffset().Y, _set->GetOffset().Z);
	}
	
protected:
	virtual void Tick(float DeltaTime) override;

	virtual void UpdateCameraPosition() override;
	virtual void DrawDebug() override;
};
