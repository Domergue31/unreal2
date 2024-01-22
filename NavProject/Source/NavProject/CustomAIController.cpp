// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAIController.h"

ACustomAIController::ACustomAIController()
{
	PrimaryActorTick.bCanEverTick = true;

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

void ACustomAIController::Init()
{
	controlledPawn = GetPawn();
	if (!controlledPawn) return;
	bAttachToPawn = true;
	AttachToPawn(controlledPawn);
	RunBehaviorTree(tree);
	//if (!tree)
	//	tree = controlledPawn->GetTree();
	//Dans le cas d l'exo de test on a qu'un seul arbre et une seul IA mais dans le cas ou on a 15 IA, on vas juste faire un arbre et le donné à l'entité puis l'entité vas le donner au controller
}
