// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_Transition/WaitForTransition.h"

void UWaitForTransition::InitTransition(UFSMObject* _fsm)
{
	Super::InitTransition(_fsm);
	GetWorld()->GetTimerManager().SetTimer(timer, this, &UWaitForTransition::Wait, randomTime ? FMath::RandRange(minTime, maxTime) : time, false);
}

bool UWaitForTransition::IsValid()
{
	return isDone;
}

void UWaitForTransition::Wait()
{
	isDone = true;
	GetWorld()->GetTimerManager().ClearTimer(timer);
}
