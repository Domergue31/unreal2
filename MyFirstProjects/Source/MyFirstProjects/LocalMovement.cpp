// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMovement.h"
#include "Utils.h"
#include <Kismet/KismetMathLibrary.h>

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


void ALocalMovement::BeginPlay()
{
    Super::BeginPlay();
    LOG_W(LogTemp, "w fwd %s / l fwd %s", *(FVector::UpVector).ToString(), *GetActorUpVector().ToString());
    onTimerReached.AddDynamic(this, &ALocalMovement::EndTimer);
    onTimerMove.AddDynamic(this, &ALocalMovement::MoveToAxe);
    onTimerMove.AddDynamic(this, &ALocalMovement::ShowTimerBox);
    onTimerMove.AddDynamic(this, &ALocalMovement::Rotate);
    onTimerMove.AddDynamic(this, &ALocalMovement::Breath);
}
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

void ALocalMovement::ShowTimerBox()
{
    const FLinearColor _progressColor = UKismetMathLibrary::LinearColorLerp(FColor::Green, FColor::Red, GetTimerProgressNormalize());
    DRAW_BOX(GetActorLocation() + FVector(0, 0, 100), (FVector(25) * GetTimerProgressNormalize()) + FVector(10), _progressColor.ToFColor(true), 2);
}

void ALocalMovement::UpdateTimer(float& _timer, const float& _maxTime)
{
    if (!isStarted)
        return;
    _timer += DELTATIME;
    if (_timer > _maxTime)
    {
        onTimerReached.Broadcast(_timer);
        return;
    }
    else
    {
        onTimerMove.Broadcast();
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

void ALocalMovement::Rotate()
{
    rotation += 1.0f;
    if (rotation == 360.0f)
        rotation = 0.0f;
    FRotator _rotation = FRotator(0, rotation, 0);
    SetActorRotation(_rotation * rotationSpeed);
}

void ALocalMovement::Breath()
{
    float _evolution = 0;
    isGrowing = scale > maxScale ? false : scale < minScale ? true : isGrowing;
    _evolution = isGrowing ? 0.1 : -0.1;
    scale += _evolution * scaleSpeed;
    FVector _scale = GetActorScale3D() + FVector(_evolution * scaleSpeed);
    SetActorScale3D(_scale);
}

void ALocalMovement::EndTimer(float& _timer)
{
    _timer = 0;
    isStarted = false;
}
