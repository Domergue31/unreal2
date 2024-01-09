// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/State.h"
#include "FSM/FSMObject.h"
#include "Kismet/KismetSystemLibrary.h"

void UState::Enter(UFSMObject* _owner)
{
	currentFSM = _owner;
	InitTransitions();
	UKismetSystemLibrary::PrintString(this, "Enter in State -> " + GetName(), true, true, FColor::Green);
}

void UState::Update()
{
	CheckForValidTransition();
	UKismetSystemLibrary::PrintString(this, "Update State -> " + GetName(), true, true, FColor::Yellow, GetWorld()->DeltaTimeSeconds);
}

void UState::Exit()
{
	UKismetSystemLibrary::PrintString(this, "Exit State -> " + GetName(), true, true, FColor::Red);
}

void UState::InitTransitions()
{
	for (TSubclassOf<UTransition> _ref : transitions)
	{
		UTransition* _transition = NewObject<UTransition>(this, _ref);
		_transition->InitTransition();
		runningTransitions.Add(_transition);
	}
}

void UState::CheckForValidTransition()
{
	for (TObjectPtr<UTransition> _transition : runningTransitions)
	{
		if (_transition->IsValidTransition())
		{
			Exit();
			currentFSM->SetNextState(_transition->GetState());
			return;
		}
	}
}
