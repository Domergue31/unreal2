// Fill out your copyright notice in the Description page of Project Settings.


#include "WeapontActor.h"

AWeapontActor::AWeapontActor()
{
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
}

void AWeapontActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapontActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(5), FColor::Red, false, -1.0f, 0, 2);
}

