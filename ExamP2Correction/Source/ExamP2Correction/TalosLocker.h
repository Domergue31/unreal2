// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TalosNode.h"
#include "TalosDoor.h"
#include "TalosLocker.generated.h"

/**
 * 
 */
UCLASS()
class EXAMP2CORRECTION_API ATalosLocker : public ATalosNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<ATalosDoor> door = nullptr;
	FTimerHandle checkTimer;
public:
	virtual void BeginPlay() override;
	virtual void NodeBehaviour() override;
	void CheckOpenDoor();
};
