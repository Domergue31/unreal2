// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCameraActor.h"


ACustomCameraActor::ACustomCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif
}

void ACustomCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->IsPlayInEditor())
	{

	}
}





bool ACustomCameraActor::ShouldTickIfViewportsOnly() const
{
	return true;
}
