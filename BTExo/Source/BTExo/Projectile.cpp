// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Alien.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(lifeTime);
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AProjectile::Move()
{
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * GetWorld()->DeltaTimeSeconds * speed);
}

void AProjectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("attack %s"), *OtherActor->GetName());
}

