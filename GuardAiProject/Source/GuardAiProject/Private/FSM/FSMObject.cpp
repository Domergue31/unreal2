// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/FSMObject.h"

void UFSMObject::StartFSM(UFSMComponent* _fsm)
{
	owner = _fsm;
	SetNextState(startingState);
}

void UFSMObject::SetNextState(TSubclassOf<UState> _state)
{
	if (!_state) return;
	currentState = NewObject<UState>(this, _state);
	currentState->Enter(this);
}

void UFSMObject::UpdateFSM()
{
	if (currentState)
		currentState->Update();
}

void UFSMObject::StopFSM()
{
	if (currentState)
		currentState->Exit();
	currentState = nullptr;
}
