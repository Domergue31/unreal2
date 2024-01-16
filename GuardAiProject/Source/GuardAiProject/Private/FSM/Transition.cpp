// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Transition.h"

void UTransition::InitTransition(UFSMObject* _fsm)
{
	currentFSM = _fsm;
}

bool UTransition::IsValid()
{
	return false;
}
