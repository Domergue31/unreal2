// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include "Kismet/KismetMathLibrary.h"

UMoveComponent::UMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	destination = GetOwner()->GetActorLocation();
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateMovement();
}

void UMoveComponent::UpdateMovement()
{
	if (IsAtDestination() || !canMove) return;
	GetOwner()->SetActorLocation(FMath::VInterpConstantTo(GetOwner()->GetActorLocation(), destination, GetWorld()->DeltaTimeSeconds, speed));
	GetOwner()->SetActorRotation(FMath::RInterpConstantTo(GetOwner()->GetActorRotation(), UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), destination), GetWorld()->DeltaTimeSeconds, speed));
}

