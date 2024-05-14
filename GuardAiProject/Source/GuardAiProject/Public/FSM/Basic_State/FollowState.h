// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/State.h"
#include "../MoveComponent.h"
#include "FollowState.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UFollowState : public UState
{
	GENERATED_BODY()
	
	TObjectPtr<AActor> player = nullptr;
	TObjectPtr<UMoveComponent> move = nullptr;

public:
	virtual void Enter(UFSMObject* _fsm);
	virtual void Update();
	virtual void Exit();
};
