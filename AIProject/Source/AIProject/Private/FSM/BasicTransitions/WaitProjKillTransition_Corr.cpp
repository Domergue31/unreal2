// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/BasicTransitions/WaitProjKillTransition_Corr.h"

void UWaitProjKillTransition_Corr::SendProjectile(TObjectPtr<AActor> _projectile)
{
	currentProjectile = _projectile;
}

bool UWaitProjKillTransition_Corr::IsValidTransition()
{
	return currentProjectile && currentProjectile->IsActorBeingDestroyed();
}
