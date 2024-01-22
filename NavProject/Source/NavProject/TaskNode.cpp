// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskNode.h"

EBTNodeResult::Type UTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* ModeMemory)
{
	Super::ExecuteTask(OwnerComp, ModeMemory);
	tree = &OwnerComp;
	brain = Cast<ACustomAIController>(OwnerComp.GetOwner());
	return EBTNodeResult::InProgress;
}
