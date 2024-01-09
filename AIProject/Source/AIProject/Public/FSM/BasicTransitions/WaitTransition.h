// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "WaitTransition.generated.h"

/**
 * 
 */
UCLASS()
class AIPROJECT_API UWaitTransition : public UTransition
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) float waitTime = 5;
	FTimerHandle waitTimer;
	bool isDone = false;
public:
	virtual void InitTransition() override;
	virtual bool IsValidTransition() override;
private:
	void Wait();
};
