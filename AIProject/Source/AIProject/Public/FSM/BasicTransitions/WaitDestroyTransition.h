// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "WaitDestroyTransition.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UWaitDestroyTransition : public UTransition
{
	GENERATED_BODY()
	
	FTimerHandle waitDestroyTimer;
	bool isDone = false;
public:
	void LaunchTimer(float _time);
	virtual bool IsValidTransition() override;


	void Destroy();
};
