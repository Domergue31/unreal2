// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	SetComponentTickInterval(.5f);
}


void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DetectObject();
}

void UInteractComponent::DetectObject()
{
	FVector _start = GetOwner()->GetActorLocation() + FVector(0, 0, interactHeight),
		_to = GetOwner()->GetActorLocation() - FVector(0,0,75) + GetOwner()->GetActorForwardVector() * interactRange;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, _start, _to, interactLayer, false, TArray<AActor*>(),
		EDrawDebugTrace::ForOneFrame, result, false);
	canGrabItem = _hit && result.Distance < 200;
	DetectObjetcFeedback(result.GetActor());
}

void UInteractComponent::DetectObjetcFeedback(TObjectPtr<AActor> _item)
{
	if (canGrabItem)
	{
		if (detectedItem)
			detectedItem->ResetDefaultColor();
		detectedItem = Cast<AInteractItem>(_item);
		detectedItem->ApplyInteractColor();
	}
	else
	{
		if (detectedItem)
			detectedItem->ResetDefaultColor();
		detectedItem = nullptr;
	}
}

void UInteractComponent::GrabObject(const FInputActionValue& _value)
{
	if (currentItem)
		return;
	if (canGrabItem)
	{
		currentItem = Cast<AInteractItem>(result.GetActor());
		currentItem->ApplyInteractColor();
		currentItem->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepWorldTransform);
		currentItem->SetActorEnableCollision(false);
	}
}

void UInteractComponent::DropObject(const FInputActionValue& _value)
{
	if (!currentItem)
		return;
	currentItem->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	currentItem->SetActorEnableCollision(true);
	currentItem->ResetDefaultColor();
	currentItem = nullptr;
}

