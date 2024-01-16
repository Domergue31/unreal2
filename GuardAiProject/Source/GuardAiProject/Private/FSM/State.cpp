// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/State.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"
#include "Kismet/KismetSystemLibrary.h"

void UState::Enter(UFSMObject* _fsm)
{
	currentFSM = _fsm;
	InitTransitions();
	UKismetSystemLibrary::PrintString(this, "Enter " + GetName(), true, false, FColor::Green);
}

void UState::Update()
{
	CheckTransitions();
}

void UState::Exit()
{
	UKismetSystemLibrary::PrintString(this, "Exit " + GetName(), true, false, FColor::Red);
}

void UState::InitTransitions()
{
	for (size_t i = 0; i < transitions.Num(); i++)
	{
		if (!transitions[i]) continue;
		UTransition* _tr = NewObject<UTransition>(this, transitions[i]);
		_tr->InitTransition(currentFSM);
		runningTransition.Add(_tr);
	}
}

void UState::CheckTransitions()
{
	for (size_t i = 0; i < runningTransition.Num(); i++)
	{
		if (runningTransition[i] && runningTransition[i]->IsValid()) 
		{
			Exit();
			currentFSM->SetNextState(runningTransition[i]->NextState());
			return;
		}
	}
}
