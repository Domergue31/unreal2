// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAIController.h"
#include "DrawDebugHelpers.h"
#include "BehaviorTree/BlackboardComponent.h"

ACustomAIController::ACustomAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACustomAIController::SetTree(UBehaviorTree* _tree)
{
	if (!_tree) return;
	currentTree = _tree;
	RunBehaviorTree(currentTree);
}

void ACustomAIController::Init()
{
	controlledCharacter = GetPawn();
	if (!controlledCharacter) return;
	bAttachToPawn = true;
	//AttachToPawn(controlledCharacter);
	RunBehaviorTree(currentTree);

}

void ACustomAIController::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void ACustomAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Debug();
}

void ACustomAIController::Debug()
{
	UBlackboardComponent* _bb = Blackboard.Get();
	if (!_bb) return;
	const FVector _location = _bb->GetValueAsVector(patrolLocKeyName);
	DrawDebugSphere(GetWorld(), _location, 100, 12, FColor::Red, false, -1, 0, 2);
}

void ACustomAIController::ReceiveTarget(AActor* _target)
{
	Blackboard->SetValueAsObject(keyTarget, _target);
}

void ACustomAIController::ReceiveDetection(bool _detected)
{
	Blackboard->SetValueAsBool(keyDetected, _detected);
}

void ACustomAIController::ReceiveIsInRange(bool _value)
{
	Blackboard->SetValueAsBool(keyIsInRange, _value);
}

