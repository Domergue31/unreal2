// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/FSMComponent.h"


UFSMComponent::UFSMComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFSMComponent::Init()
{
	if (!currentFSMType) return;

	runningFSM = NewObject<UFSMObject>(this, currentFSMType);
	runningFSM->StartFSM(this);
}

void UFSMComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UFSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateFSM();
}

void UFSMComponent::EndPlay(EEndPlayReason::Type _end)
{
	CloseFSM();
	Super::EndPlay(_end);
}

void UFSMComponent::CloseFSM()
{
	if (!runningFSM) return;
	runningFSM->StopFSM();
}


void UFSMComponent::UpdateFSM()
{
	if (!runningFSM) return;
	runningFSM->UpdateFSM();
}

