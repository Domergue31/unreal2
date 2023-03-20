// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveOnGridComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include "Utils.h"

// Sets default values for this component's properties
UMoveOnGridComponent::UMoveOnGridComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMoveOnGridComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


// Called every frame
void UMoveOnGridComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToLocation();
	LookAtDirection();
}

void UMoveOnGridComponent::Init()
{
	if (!grid)
		return;
	grid->OnGridLocation().AddDynamic(this, &UMoveOnGridComponent::SetLocation);
}

void UMoveOnGridComponent::SetLocation(FVector _location)
{
	targetLocation = _location + offset;
}

void UMoveOnGridComponent::MoveToLocation()
{
	const FVector _lerpMovement = FMath::Lerp(GetOwner()->GetActorLocation(), targetLocation, GetWorld()->DeltaTimeSeconds * 3);
	GetOwner()->SetActorLocation(_lerpMovement);
}

void UMoveOnGridComponent::LookAtDirection()
{
	const FRotator _rot = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), targetLocation);
	const FRotator _lerp = FMath::Lerp(GetOwner()->GetActorRotation(), _rot, DELTATIME * 5);
	GetOwner()->SetActorRotation(_lerp);
}

