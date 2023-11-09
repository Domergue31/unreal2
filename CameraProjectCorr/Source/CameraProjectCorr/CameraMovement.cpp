// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraMovement.h"

ACameraMovement::ACameraMovement()
{
	PrimaryActorTick.bCanEverTick = true;
	#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
	#endif
}

void ACameraMovement::BeginPlay()
{
	Super::BeginPlay();
}

void ACameraMovement::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetWorld()->IsPlayInEditor())
		UpdateCameraPosition();
	DrawDebug();

}

void ACameraMovement::UpdateCameraPosition()
{
}

void ACameraMovement::DrawDebug()
{
}

bool ACameraMovement::ShouldTickIfViewportsOnly() const
{
	return useDebug;
}
