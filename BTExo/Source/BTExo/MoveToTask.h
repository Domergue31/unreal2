// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskNode.h"
#include "MoveToTask.generated.h"

/**
 * 
 */
UCLASS()
class BTEXO_API UMoveToTask : public UTaskNode
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) float range = 30;
	UPROPERTY(EditAnywhere) FName AlienBTKey_Target = "";

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
