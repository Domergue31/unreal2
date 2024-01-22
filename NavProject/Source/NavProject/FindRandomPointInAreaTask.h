// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskNode.h"
#include "FindRandomPointInAreaTask.generated.h"

/**
 * 
 */
UCLASS()
class NAVPROJECT_API UFindRandomPointInAreaTask : public UTaskNode
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) FVector randomLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere) float radius = 1000;
	UPROPERTY(EditAnywhere) FName patrolLocationBBKeyName = "";

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* ModeMemory) override;
};
