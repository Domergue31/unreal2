// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMovementCorrection.h"
#include "Utils.h"

ALocalMovementCorrection::ALocalMovementCorrection()
{
    PrimaryActorTick.bCanEverTick = true;
    mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = mesh;
    InitObject();
}

void ALocalMovementCorrection::InitObject()
{
    mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
    mesh->SetMaterial(0, LoadObject<UMaterialInterface>(this, TEXT("'/Engine/VREditor/UI/DiscMaterial.DiscMaterial'")));
}

void ALocalMovementCorrection::BeginPlay()
{
    Super::BeginPlay();
    initScale = GetActorScale();
    LOG_W(LogTemp, "w fwd %s / l fwd %s", *(FVector::UpVector).ToString(), *GetActorUpVector().ToString());
    onEndTimer.AddDynamic(this, &ALocalMovementCorrection::StopMovement);
    onEndTimer.AddDynamic(this, &ALocalMovementCorrection::StopRotation);
}

void ALocalMovementCorrection::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    DebugAxis();
    Move(GetActorForwardVector(), speed);
    Rotate(FRotator(0,1,0), rotateSpeed);
    BreathOfTheScale(scaleSpeed);
    UpdateTimer(timer);
    DRAW_TEXT(GetActorLocation(), FString::Printf(TEXT("%d/%d"), (int)GetTimerProgress(), (int)MaxTimeDelay), FColor::White, 2);
    const FColor _lerpColor = LERP_COLOR(FColor::Red, FColor::Green, GetTimerProgress());
    DRAW_BOX(GetActorLocation() + GetActorUpVector() * 200, FVector(50) * GetTimerProgress(), _lerpColor, 2);
    DRAW_LINE(GetActorLocation(), GetActorLocation() + GetActorUpVector() * 300, FColor::White, 2);
}

void ALocalMovementCorrection::DebugAxis()
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

void ALocalMovementCorrection::Move(const FVector& _direction, const float& _speed)
{
    if (!canMove)
        return;
    AddActorLocalOffset((_direction.GetSafeNormal() * _speed * DELTATIME));
    //const FVector _next = GetActorLocation() + (_direction.GetSafeNormal() * _speed * DELTATIME);
    //SetActorLocation(_next);
}

void ALocalMovementCorrection::Rotate(const FRotator& _rotation, const float& _speed)
{
    if (!canRotate)
        return;
    AddActorLocalRotation(_rotation * _speed * DELTATIME);
    //const FRotator _nextRotation = GetActorRotation() + _rotation * _speed * DELTATIME;
    //SetActorRotation(_nextRotation);
}

void ALocalMovementCorrection::BreathOfTheScale(const float& _scaleSpeed)
{
    const float _breathValue = FMath::Sin(WORLD->TimeSeconds * _scaleSpeed);
    SetActorScale3D(initScale + (initScale * FMath::Abs(_breathValue)));
}

void ALocalMovementCorrection::StopMovement()
{
    SetCanMove(false);
}

UFUNCTION() void ALocalMovementCorrection::StopRotation()
{
    SetCanRotate(false);
}

void ALocalMovementCorrection::UpdateTimer(float& _timer)
{
    if (!timerStarted)
        return;
    _timer += DELTATIME;
    if (GetEndTimer())
    {
        onEndTimer.Broadcast();
        timerStarted = false;
    }
}
