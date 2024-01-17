// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/Basic_State/ResearchState.h"
#include "FSM/FSMObject.h"
#include "FSM/FSMComponent.h"
#include "../PathRunnerComponent.h"
#include "../GuardGameMode.h"


void UResearchState::Enter(UFSMObject* _fsm)
{
	Super::Enter(_fsm);



	AGuardGameMode* _gm = GetWorld()->GetAuthGameMode<AGuardGameMode>();
	if (!_gm) return;
	/*UPathManager* _manager = _gm->GetPathManager();
	if (!_manager) return;*/
	UWaypointManager* _manager = _gm->GetWaypointManager();
	if (!_manager) return;

	UPathRunnerComponent* _runner = _fsm->GetOwner()->GetOwner()->GetComponentByClass<UPathRunnerComponent>();
	if (!_runner) return;
	AWaypoint* _point = _manager->GetNearestPoint(_fsm->GetOwner()->GetOwner()->GetActorLocation());
	APath* _path = _point->GetPathOwner();
	/*_runner->Restart();*/
	_runner->SetIndex(_path->IndexOf(_point));
	_runner->SetCurrentPath(_path);
}
