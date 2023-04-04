// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMovingComponent.h"

UEnemyMovingComponent::UEnemyMovingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}
void UEnemyMovingComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}
void UEnemyMovingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Move();
	DrawDebugBox(GetWorld(), initLocation, FVector(5), FColor::Red, false, - 1, 0, 2);
	DrawDebugBox(GetWorld(), targetLocation, FVector(5), FColor::Green, false, - 1, 0, 2);
	DrawDebugLine(GetWorld(), targetLocation, initLocation, FColor::Yellow, false, -1, 0, 2);
}
void UEnemyMovingComponent::Init()
{
	initLocation = GetOwnerLocation();
	targetLocation = initLocation + GetOwner()->GetActorForwardVector() * sizeMovement;
	currentLocation = targetLocation;
}
void UEnemyMovingComponent::Stop()
{
	canMove = false;
}


void UEnemyMovingComponent::Move()
{
	if (!canMove)
		return;
	const FVector _next = FMath::VInterpConstantTo(GetOwnerLocation(), currentLocation, GetWorld()->DeltaTimeSeconds, speed);
	SetOwnerLocation(_next);
	if (IsAtLocation())
	{
		SetOwnerRotation(GetOwnerRotation() + FRotator(0, 180, 0));
		toTarget = !toTarget;
		currentLocation = toTarget ? targetLocation : initLocation;
	}
}

bool UEnemyMovingComponent::IsAtLocation() const
{
	return FVector::Distance(GetOwnerLocation(), currentLocation) < 10;
}

