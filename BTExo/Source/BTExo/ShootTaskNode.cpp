// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootTaskNode.h"

EBTNodeResult::Type UShootTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);
    if (!projectileRef)
        return EBTNodeResult::Failed;
    AProjectile* _projectile = GetWorld()->SpawnActor<AProjectile>(projectileRef, brain->GetControlledPawn()->GetActorLocation(), FRotator::ZeroRotator);
    _projectile->SetActorRotation(brain->GetControlledPawn()->GetActorRotation());
    return EBTNodeResult::Succeeded;
}
