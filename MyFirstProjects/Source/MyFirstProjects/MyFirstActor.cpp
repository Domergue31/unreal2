// Fill out your copyright notice in the Description page of Project Settings.
#include "MyfirstActor.h"
#include "Utils.h"

// Sets default values
AMyfirstActor::AMyfirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	InitObject();
}

#pragma region CUSTOM_METHODS
void AMyfirstActor::MoveToLocation(const FVector& _target)
{
    originLocator = _target;
    MoveToLocation();
}
void AMyfirstActor::InitObject()
{
    mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
    mesh->GetStaticMesh()->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'")));
}

FVector AMyfirstActor::GetFromPoint()
{
    return GetActorLocation();
}

void AMyfirstActor::MoveToLocation()
{
    if (!isInstantSpawn)
        return;
    SetActorLocation(GetSpawnLocation());
}

void AMyfirstActor::DrawDebug()
{
    if (!drawDebug)
        return;
    UWorld* _w = GetWorld();
    DRAW_SPHERE(GetActorLocation(), 100, FColor::Green, 2)
        DRAW_BOX(fromLocation, FVector(100), FColor::Yellow, 2)
        DRAW_LINE(fromLocation, GetActorLocation(), FColor::Red, 1)
        DRAW_SPHERE(originLocator, 50, FColor::Yellow, 2)
        DRAW_LINE(originLocator, fromLocation, FColor::Red, 1)
        DRAW_TEXT(fromLocation, *fromLocation.ToCompactString(), FColor::Red, DELTATIME)
}
void AMyfirstActor::MoveToLocation_Interp(const float& _speed)
{
    if (!canMove)
        return;
    const FVector _result = FMath::VInterpConstantTo(GetActorLocation(), GetSpawnLocation(), DELTATIME, _speed);
    SetActorLocation(_result);
}
#pragma endregion CUSTOM_METHODS

void AMyfirstActor::BeginPlay()
{
    Super::BeginPlay();
    if (isControlBy)
        return;
    canMove = !isInstantSpawn;
    fromLocation = GetFromPoint();
    MoveToLocation();
}

void AMyfirstActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (isControlBy)
        return;
    MoveToLocation_Interp(speed);
    DrawDebug();

}