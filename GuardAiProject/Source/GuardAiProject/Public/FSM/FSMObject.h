// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.h"
#include "FSMObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GUARDAIPROJECT_API UFSMObject : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TSubclassOf<UState> startingState = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<UState> currentState = nullptr;

	TObjectPtr<class UFSMComponent> owner = nullptr;

public:
	FORCEINLINE TObjectPtr<UFSMComponent> GetOwner() { return owner; }
	virtual void StartFSM(UFSMComponent* _fsm);
	void SetNextState(TSubclassOf<UState> _state);
	virtual void UpdateFSM();
	virtual void StopFSM();

};
