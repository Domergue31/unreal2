// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

ABlock::ABlock()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}

void ABlock::BeginPlay()
{
	Super::BeginPlay();
}

void ABlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlock::Break()
{
	SetLifeSpan(0.1f);
}

void ABlock::Active()
{

}

