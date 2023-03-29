// Fill out your copyright notice in the Description page of Project Settings.


#include "Elements.h"

AElements::AElements()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AElements::BeginPlay()
{
	Super::BeginPlay();
	
}

void AElements::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElements::NotifyActorBeginOverlap(AActor* _other)
{
}

