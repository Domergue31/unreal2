// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_State/LostState.h"
#include "../PathRunnerComponent.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"

void ULostState::Enter(UFSMObject* _fsm)
{
	Super::Enter(_fsm);

	UPathRunnerComponent* _runner = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UPathRunnerComponent>();
	if (!_runner) return;
	_runner->SetIndexPrevious();
}
