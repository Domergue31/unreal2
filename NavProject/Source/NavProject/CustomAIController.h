// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CustomAIController.generated.h"

/**
 * 
 */
UCLASS()
class NAVPROJECT_API ACustomAIController : public AAIController
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<UBehaviorTree> tree = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<APawn> controlledPawn = nullptr;

public:
public:
	TObjectPtr<APawn> GetControlledPawn() { return controlledPawn; }
public:

	ACustomAIController();
protected:
	void Init();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
