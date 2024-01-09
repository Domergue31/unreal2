// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"

void UFSMObject::StartFSM(UFSMComponent* _owner)
{
	owner = _owner;
	SetNextState(startingState);
}

void UFSMObject::SetNextState(TSubclassOf<UState> _state)
{
	if (!_state)
		return;
	currentState = NewObject<UState>(this, _state);
	currentState->Enter(this);
}

void UFSMObject::UpdateFSM()
{
	if (!currentState) return;
	currentState->Update();
}

void UFSMObject::StopFSM()
{
	if (!currentState) return;
	currentState->Exit();
	currentState = nullptr;
}
