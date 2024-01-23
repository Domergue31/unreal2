// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "CustomAIController.h"
#include "TaskNode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class BTEXO_API UTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	UPROPERTY() TObjectPtr<ACustomAIController> brain = nullptr;
	UPROPERTY() TObjectPtr<UBehaviorTreeComponent> tree = nullptr;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
