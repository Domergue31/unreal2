// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TaskNode.h"
#include "Projectile.h"
#include "ShootTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class BTEXO_API UShootTaskNode : public UTaskNode
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TSubclassOf<AProjectile> projectileRef = nullptr;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
