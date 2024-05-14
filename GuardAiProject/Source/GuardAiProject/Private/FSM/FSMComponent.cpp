// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/FSMComponent.h"

UFSMComponent::UFSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFSMComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!FSMRef) return;
	currentFSM = NewObject<UFSMObject>(this, FSMRef);
	currentFSM->StartFSM(this);
}


void UFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (currentFSM)
		currentFSM->UpdateFSM();
}

void UFSMComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (currentFSM)
		currentFSM->StopFSM();
}

