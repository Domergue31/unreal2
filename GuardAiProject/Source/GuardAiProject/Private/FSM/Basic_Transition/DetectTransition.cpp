// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_Transition/DetectTransition.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"

void UDetectTransition::InitTransition(UFSMObject* _fsm)
{
	Super::InitTransition(_fsm);
	sight = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UGuardSightSystemComponent>();
}

bool UDetectTransition::IsValid()
{
	return sight && sight->TargetSight();
}
