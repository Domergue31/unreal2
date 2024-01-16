// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/State.h"
#include "LostState.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API ULostState : public UState
{
	GENERATED_BODY()
	
public:
	virtual void Enter(UFSMObject* _fsm) override;
};
