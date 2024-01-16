// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_Transition/LoseDetectionTransition.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"

void ULoseDetectionTransition::InitTransition(UFSMObject* _fsm)
{
	Super::InitTransition(_fsm);
	sight = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UGuardSightSystemComponent>();
}

bool ULoseDetectionTransition::IsValid()
{
	return sight && !sight->TargetSight();
}
