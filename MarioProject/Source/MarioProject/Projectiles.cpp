// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles.h"

AProjectiles::AProjectiles()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}

void AProjectiles::InitProjectile(const float& _lifeSpan)
{
	SetLifeSpan(_lifeSpan);
}

void AProjectiles::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Behaviour();
}

void AProjectiles::Behaviour()
{
	AddActorWorldOffset(GetActorForwardVector() * GetWorld()->DeltaTimeSeconds * projectilesSpeed);
}

