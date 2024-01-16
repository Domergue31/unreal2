// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_State/MoveState.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"
#include "../PathRunnerComponent.h"

void UMoveState::Enter(UFSMObject* _fsm)
{
	Super::Enter(_fsm);
	UPathRunnerComponent* _runner = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UPathRunnerComponent>();
	if (!_runner) return;

	move = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UMoveComponent>();
	if (!move) return;
	move->SetDestination(_runner->GetPoint());
	_runner->SetIndexNext();
	move->SetCanMove(true);
}

void UMoveState::Exit()
{
	if (move)
		move->SetCanMove(false);
}
