// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAIController.h"

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
	controlledCharacter = Cast<AAICharacter>(GetCharacter());
	if (!controlledCharacter) return;
	bAttachToPawn = true;
	AttachToPawn(controlledCharacter);
	currentTree = controlledCharacter->GetTree();
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
}

