// Fill out your copyright notice in the Description page of Project Settings.


#include "Follower.h"
#include "Utils.h"

UFollower::UFollower()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFollower::BeginPlay()
{
	Super::BeginPlay();
	SetTarget(WORLD->GetFirstPlayerController()->GetPawn());
}


void UFollower::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    DRAW_SPHERE(GetTargetLocation(), 50, FColor::Green, 2);
    DRAW_LINE(GetTargetLocation(), GetActorLocation(), FColor::Green, 2);
    DRAW_BOX(GetFinalLocation(), FVector(10), FColor::Red, 2);
    DRAW_LINE(GetFinalLocation(), GetActorLocation(), FColor::Red, 2);
    FollowTarget();
    ReplicateRollAngle();
    LookAtTarget();
}


FVector UFollower::GetFinalLocation() const
{
    if (!target)
        return GetActorLocation();
    FVector _offset;
    switch (settings.axis)
    {
    case X:
        _offset = target->GetActorForwardVector();
        break;
    case InvertX:
        _offset = -target->GetActorForwardVector();
        break;
    case Y:
        _offset = target->GetActorRightVector();
        break;
    case InvertY:
        _offset = -target->GetActorRightVector();
        break;
    }
    return (GetTargetLocation() + _offset * settings.distance) + FVector(0, 0, settings.height);
}


void UFollower::FollowTarget()
{
    GetOwner()->SetActorLocation(FMath::Lerp(GetActorLocation(), GetFinalLocation(), DELTATIME * settings.speed));
}

void UFollower::ReplicateRollAngle()
{
    if (!settings.replicateRoll)
        return;
    FRotator _rot = GetOwner()->GetActorRotation();
    _rot.Roll = target->GetActorRotation().Roll;
    GetOwner()->SetActorRotation(_rot);
}


void UFollower::LookAtTarget()
{
    if (!settings.useLookAt || !target)
        return;
    FRotator _rot = GetOwner()->GetActorRotation();
    FRotator _newRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetFinalLocation());
    _rot.Yaw = _newRot.Yaw;
    GetOwner()->SetActorRotation(_rot);
}