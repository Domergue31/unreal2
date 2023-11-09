// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraActorFollow.h"

ACameraActorFollow::ACameraActorFollow()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACameraActorFollow::Tick(float DeltaTime)
{
	ACameraActorMovement::Tick(DeltaTime);
}

void ACameraActorFollow::UpdateCameraPosition()
{
	TObjectPtr<UCameraSettingsFollow> _set = Cast<UCameraSettingsFollow>(cameraSettings);
	if (_set->GetMovementType() == EMovementType::Lerp)
		SetActorLocation(FMath::Lerp(GetActorLocation(), GetFinalLocation(), _set->GetCameraSpeed() / 200 * GetWorld()->DeltaTimeSeconds));
	else
		SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), GetFinalLocation(),GetWorld()->DeltaTimeSeconds, _set->GetCameraSpeed()));
}

void ACameraActorFollow::DrawDebug()
{
	ACameraActorMovement::DrawDebug();
}
