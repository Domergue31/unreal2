// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectionComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"

UDetectionComponent::UDetectionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UDetectionComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UDetectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Detect();
}

void UDetectionComponent::Detect()
{
	FHitResult _result;
	const FVector _startLoc = GetOwner()->GetActorLocation();

	const bool _hit = UKismetSystemLibrary::SphereTraceSingleForObjects(GetWorld(), _startLoc, _startLoc, detectionRange, layerToDetect,
		false, { GetOwner() }, EDrawDebugTrace::ForOneFrame, _result, true);

	if (!_hit)
	{
		/*target = nullptr;
		targetDetected = false;
		onTargetFound.Broadcast(target);
		onTargetDetected.Broadcast(targetDetected);*/
		return;
	}
	target = _result.GetActor();
	targetDetected = true;
	onTargetFound.Broadcast(target);
	onTargetDetected.Broadcast(targetDetected);
}

void UDetectionComponent::Debug()
{
}

