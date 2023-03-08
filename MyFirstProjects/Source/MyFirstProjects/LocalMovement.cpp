// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMovement.h"
#include "Utils.h"

ALocalMovement::ALocalMovement()
{
    PrimaryActorTick.bCanEverTick = true;
    mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = mesh;
    InitObject();
}

void ALocalMovement::InitObject()
{
    mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
    mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Engine/VREditor/UI/DiscMaterial.DiscMaterial'")));
}

// Called when the game starts or when spawned
void ALocalMovement::BeginPlay()
{
    Super::BeginPlay();
    LOG_W(LogTemp, "w fwd %s / l fwd %s", *(FVector::UpVector).ToString(), *GetActorUpVector().ToString());
}

// Called every frame
void ALocalMovement::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (isDebuging)
        DebugAxis();
    UpdateTimer(timer, MaxTime);

}

void ALocalMovement::DebugAxis()
{
    const FVector _location = GetActorLocation();
    const FVector _right = GetActorRightVector().GetSafeNormal();
    const FVector _fwd = GetActorForwardVector().GetSafeNormal();
    const FVector _up = GetActorUpVector().GetSafeNormal();

    //FWD
    DRAW_LINE(_location, _location + _fwd * 100, FColor::Red, 2)
    DRAW_SPHERE(_location + _fwd * 100, 20, FColor::Red, 2)
    //UP
    DRAW_LINE(_location, _location + _right * 100, FColor::Green, 2)
    DRAW_SPHERE(_location + _right * 100, 20, FColor::Green, 2)
    //RIGHT
    DRAW_LINE(_location, _location + _up * 100, FColor::Blue, 2)
    DRAW_SPHERE(_location + _up * 100, 20, FColor::Blue, 2)
}

void ALocalMovement::UpdateTimer(float& _timer, const float& _maxTime)
{
    if (!isStarted)
        return;
    _timer += DELTATIME;
    if (_timer > _maxTime)
    {
        _timer = 0;
        isStarted = false;
        return;
    }
    else
    {
        MoveToAxe();
    }
}

void ALocalMovement::MoveToAxe()
{
    const FVector _location = GetActorLocation();
    const FVector _right = GetActorRightVector().GetSafeNormal();
    const FVector _fwd = GetActorForwardVector().GetSafeNormal();
    const FVector _up = GetActorUpVector().GetSafeNormal();

    //FWD
    if (isForwardAxe)
    {
        FVector _newLocation = _location + _fwd * 5 * speed;
        SetActorLocation(_newLocation);
    }
    //UP
    if (isRightAxe)
    {
        FVector _newLocation = _location + _right * 5 * speed;
        SetActorLocation(_newLocation);
    }
    //RIGHT
    if (isUpAxe)
    {
        FVector _newLocation = _location + _up * 5 * speed;
        SetActorLocation(_newLocation);
    }
}
