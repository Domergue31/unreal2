// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

EBTNodeResult::Type UMoveToTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AActor* _self = brain->GetControlledPawn();
	AActor* _actor = Cast<AActor>(brain.Get()->GetBlackboardComponent()->GetValueAsObject(AlienBTKey_Target));
	if (!_actor || !_self)
	{
		UE_LOG(LogTemp, Warning, TEXT("move To Actor : null"));
		return EBTNodeResult::Failed;
	}
	if (_self->GetActorLocation().Equals(_actor->GetActorLocation(), range))
		return EBTNodeResult::Succeeded;
	_self->SetActorLocation(FMath::VInterpConstantTo(_self->GetActorLocation(), FVector(_actor->GetActorLocation().X, _actor->GetActorLocation().Y, _self->GetActorLocation().Z), GetWorld()->DeltaTimeSeconds, 1000));
	FRotator _newRot = UKismetMathLibrary::FindLookAtRotation(_self->GetActorLocation(), _actor->GetActorLocation());
	_self->SetActorRotation(FMath::RInterpConstantTo(_self->GetActorRotation(), FRotator(0, _newRot.Yaw, 0), GetWorld()->DeltaTimeSeconds, 0));
	return EBTNodeResult::Failed;
}
