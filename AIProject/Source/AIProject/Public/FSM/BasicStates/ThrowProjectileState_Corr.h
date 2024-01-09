// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/State.h"
#include "FSM/BasicTransitions/WaitProjKillTransition_Corr.h"
#include "ThrowProjectileState_Corr.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UThrowProjectileState_Corr : public UState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<AActor> projectile = nullptr;
	UPROPERTY() TObjectPtr<UWaitProjKillTransition_Corr>  waitForKill = nullptr;

public:
	virtual void Enter(class UFSMObject* _owner) override;
	virtual void InitTransitions() override;
};
