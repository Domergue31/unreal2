// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanetCorrection.h"

// Sets default values
APlanetCorrection::APlanetCorrection()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Sphere.Sphere'")));
	mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Game/StarterContent/Materials/M_Wood_Pine.M_Wood_Pine")));
}

void APlanetCorrection::InitPlanet()
{
	const float _randSizeScale = useRandomScale ? FMath::FRandRange(.5f, 5) : 1;
	initScale = GetActorScale() * _randSizeScale;
	SetActorScale3D(initScale);
}


void APlanetCorrection::UpdateSize(const FVector& _location)
{
	const float _currentDistance = GetCurrentDistanceTo(_location);
	SetActorScale3D(initScale * (1 - _currentDistance / initDistance));
}


// Called when the game starts or when spawned
void APlanetCorrection::BeginPlay()
{
	Super::BeginPlay();
	InitPlanet();
}

// Called every frame
void APlanetCorrection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

