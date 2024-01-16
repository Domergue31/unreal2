// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSM/Transition.h"
#include "NoWaitTransition.generated.h"

/**
 * 
 */
UCLASS()
class GUARDAIPROJECT_API UNoWaitTransition : public UTransition
{
	GENERATED_BODY()
	

public:
	virtual bool IsValid() override;

};
