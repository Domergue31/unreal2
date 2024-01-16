// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/State.h"
#include "../MoveComponent.h"
#include "MoveState.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UMoveState : public UState
{
	GENERATED_BODY()
	

	TObjectPtr<UMoveComponent> move = nullptr;
public:
	virtual void Enter(UFSMObject* _fsm) override;
	virtual void Exit() override;
};
