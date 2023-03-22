// Fill out your copyright notice in the Description page of Project Settings.


#include "TridusSpell.h"

ATridusSpell::ATridusSpell()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void ATridusSpell::BeginPlay()
{
	Super::BeginPlay();
}

void ATridusSpell::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}

