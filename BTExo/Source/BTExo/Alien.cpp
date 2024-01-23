// Fill out your copyright notice in the Description page of Project Settings.


#include "Alien.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"


AAlien::AAlien()
{
	PrimaryActorTick.bCanEverTick = true;
	sight = CreateDefaultSubobject<UAlienSightSystemComponent>("AlienSight");
	AddOwnedComponent(sight);
}
void AAlien::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(sightTimer, this, &AAlien::Detect, 0.1f, true);
	aiController = Cast<ACustomAIController>(UAIBlueprintHelperLibrary::GetAIController(this));
}
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AAlien::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAlien::Detect()
{

}

