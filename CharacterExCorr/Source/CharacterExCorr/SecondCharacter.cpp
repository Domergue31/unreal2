// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondCharacter.h"

ASecondCharacter::ASecondCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASecondCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASecondCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecondCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

