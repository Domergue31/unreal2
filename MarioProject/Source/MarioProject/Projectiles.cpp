// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles.h"
#include "MarioProjectCharacter.h"

AProjectiles::AProjectiles()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}

void AProjectiles::InitProjectile(const float& _lifeSpan)
{
	UE_LOG(LogTemp, Warning, TEXT("%f"), _lifeSpan);
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
	IsDestroy();
}

void AProjectiles::NotifyActorBeginOverlap(AActor* _other)
{
	AMarioProjectCharacter* _char = Cast<AMarioProjectCharacter>(_other);
	if (_char)
		return;
	destroy = true;
}

void AProjectiles::Behaviour()
{
	AddActorWorldOffset(GetActorForwardVector() * GetWorld()->DeltaTimeSeconds * projectilesSpeed);
}

void AProjectiles::IsDestroy()
{
	if (destroy)
		Destroy();
}

