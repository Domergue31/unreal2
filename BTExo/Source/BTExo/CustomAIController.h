// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AICharacter.h"
#include "CustomAIController.generated.h"

/**
 * 
 */
UCLASS()
class BTEXO_API ACustomAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere) TObjectPtr<UBehaviorTree> currentTree = nullptr;
	UPROPERTY(VisibleAnywhere) TObjectPtr<AAICharacter> controlledCharacter = nullptr;


public:
	FORCEINLINE TObjectPtr<APawn> GetControlledPawn() { return controlledCharacter; }
	FORCEINLINE TObjectPtr<UBehaviorTree> GetCurrentTree() { return currentTree; }
	ACustomAIController();
	void SetTree(UBehaviorTree* _tree);
protected:
	void Init();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
