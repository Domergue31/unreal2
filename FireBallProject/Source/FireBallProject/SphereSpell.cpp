// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereSpell.h"

// Sets default values
ASphereSpell::ASphereSpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}

// Called when the game starts or when spawned
void ASphereSpell::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(5);
}

// Called every frame
void ASphereSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void ASphereSpell::Move()
{
	FVector _result = GetActorForwardVector().GetSafeNormal();
	SetActorLocation(GetActorLocation() + _result * GetWorld()->DeltaTimeSeconds * speed);
}
