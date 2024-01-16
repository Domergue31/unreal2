// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_Transition/WaitDestinationTransition.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"

void UWaitDestinationTransition::InitTransition(UFSMObject* _fsm)
{
	Super::InitTransition(_fsm);
	move = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UMoveComponent>();
}

bool UWaitDestinationTransition::IsValid()
{
	return move && move->IsAtDestination();
}
