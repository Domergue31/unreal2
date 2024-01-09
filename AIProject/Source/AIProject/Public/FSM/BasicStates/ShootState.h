// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/State.h"
#include "ShootState.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UShootState : public UState
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TSubclassOf<AActor> bulletRef = nullptr;
	UPROPERTY(EditAnywhere) float bulletLifeTime = 5;

public:
	virtual void Enter(class UFSMObject* _owner) override;
private:
	void SetWaitDestroyTransition();
};
