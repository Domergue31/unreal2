// Fill out your copyright notice in the Description page of Project Settings.


#include "TalosLocker.h"

void ATalosLocker::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(checkTimer, this, &ATalosLocker::CheckOpenDoor, 1, true);
}

void ATalosLocker::NodeBehaviour()
{
	Super::NodeBehaviour();
	if (door)
		DrawDebugLine(GetWorld(), GetActorLocation(), door->GetActorLocation(), FColor::Yellow, false, -1, 0, 5);
}

void ATalosLocker::CheckOpenDoor()
{
	if (!door)
		return;
	isSource ? door->OpenDoor() : door->CloseDoor();
	isSource = false;
}
