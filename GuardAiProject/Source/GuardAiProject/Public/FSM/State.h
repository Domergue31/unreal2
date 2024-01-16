// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Transition.h"
#include "State.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GUARDAIPROJECT_API UState : public UObject
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TArray<TSubclassOf<UTransition>> transitions = {};
	UPROPERTY(VisibleAnywhere) TArray<UTransition*> runningTransition = {};

	TObjectPtr<class UFSMObject> currentFSM = nullptr;

public:
	virtual void Enter(UFSMObject* _fsm);
	virtual void Update();
	virtual void Exit();

protected:
	virtual void InitTransitions();
	void CheckTransitions();
};
