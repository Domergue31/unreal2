// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienCAC.h"
#include "BehaviorTree/BlackboardComponent.h"

void AAlienCAC::BeginPlay()
{
	Super::BeginPlay();

}

void AAlienCAC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAlienCAC::Detect()
{
	Super::Detect();
	if (sight->GetTargetSight() && aiController->GetCurrentTree() != attackTree)
	{
		aiController->SetTree(attackTree);
		aiController.Get()->GetBlackboardComponent()->SetValueAsObject(alienBTKey_TargetActor, sight->GetTargetSight());
	}
	else if (!sight->GetTargetSight() && aiController->GetCurrentTree() == attackTree)
	{
		aiController->SetTree(tree);
		aiController.Get()->GetBlackboardComponent()->SetValueAsObject(alienBTKey_TargetActor, sight->GetTargetSight());
	}
}
