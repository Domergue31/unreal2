// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomPointInAreaTask.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UFindRandomPointInAreaTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* ModeMemory)
{
	Super::ExecuteTask(OwnerComp, ModeMemory);
	UNavigationSystemV1* _nav = UNavigationSystemV1::GetCurrent(GetWorld());
	FVector _origin = brain.Get()->GetControlledPawn()->GetActorLocation();
	FNavLocation _point;
	const bool _success = _nav->GetRandomPointInNavigableRadius(_origin, radius, _point);
	if (!_success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to find random point during Task"));
		return EBTNodeResult::Failed;
	}
	randomLocation = _point.Location;
	brain.Get()->GetBlackboardComponent()->SetValueAsVector(patrolLocationBBKeyName, randomLocation);
	return EBTNodeResult::Succeeded;
}
