// Fill out your copyright notice in the Description page of Project Settings.


#include "Waypoint.h"
#include "GuardGameMode.h"

AWaypoint::AWaypoint()
{
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;

}

void AWaypoint::BeginPlay()
{
	Super::BeginPlay();	
	AGuardGameMode* _gm = GetWorld()->GetAuthGameMode<AGuardGameMode>();
	if (_gm)
		_gm->GetWaypointManager()->Register(this);
}

