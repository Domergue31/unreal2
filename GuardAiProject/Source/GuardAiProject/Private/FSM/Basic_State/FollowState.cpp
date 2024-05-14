// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_State/FollowState.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"
#include "FSM/GuardSightSystemComponent.h"

void UFollowState::Enter(UFSMObject* _fsm)
{
	Super::Enter(_fsm);
	UGuardSightSystemComponent* _sight = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UGuardSightSystemComponent>();
	if (_sight)
		player = _sight->TargetSight();
	move = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UMoveComponent>();
}

void UFollowState::Update()
{
	Super::Update();
	if (!move || !player) return;
	move->SetDestination(player->GetActorLocation());
	move->SetCanMove(true);
}

void UFollowState::Exit()
{
	Super::Exit();
	move->SetCanMove(false);
}
