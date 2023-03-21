// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowerComponent.h"
#include "MainCharacter.h"
#include <Kismet/KismetMathLibrary.h>

UFollowerComponent::UFollowerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFollowerComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UFollowerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FollowTarget();
	LookAtTarget();
}

void UFollowerComponent::FollowTarget()
{
	if (!target || !follow)
		return;
	FVector _destination = GetTargetLocation() - target->GetActorForwardVector() * distance;
	GetOwner()->SetActorLocation(FMath::VInterpTo(GetActorLocation(), _destination, GetWorld()->DeltaTimeSeconds, speed));
	TObjectPtr<AMainCharacter> _pawn = Cast<AMainCharacter>(target);
}

void UFollowerComponent::LookAtTarget()
{
	if (!target || !follow)
		return;
	FVector _destination = GetTargetLocation() - target->GetActorForwardVector() * distance;
	FRotator _rot = GetOwner()->GetActorRotation();
	FRotator _newRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), _destination);
	_rot.Yaw = _newRot.Yaw;
	GetOwner()->SetActorRotation(_rot);
}

