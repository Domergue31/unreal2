// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackNode.h"
#include "Ennemy.h"
#include "AttackComponent.h"

EBTNodeResult::Type UAttackNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AEnnemy* _enemy = Cast<AEnnemy>(brain->GetControlledPawn());
	if (!_enemy) return EBTNodeResult::Failed;
	_enemy->GetAttack()->Attack();
	return EBTNodeResult::Succeeded;
}
