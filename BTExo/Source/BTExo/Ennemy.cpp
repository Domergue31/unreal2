// Fill out your copyright notice in the Description page of Project Settings.


#include "Ennemy.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AttackComponent.h"

AEnnemy::AEnnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	//RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	collider = CreateDefaultSubobject<UCapsuleComponent>("Collider");
	collider->SetupAttachment(RootComponent);
	skeleton = CreateDefaultSubobject<USkeletalMeshComponent>("Skeleton");
	skeleton->SetupAttachment(collider);
	detection = CreateDefaultSubobject<UDetectionComponent>("Detection");
	attack = CreateDefaultSubobject<UAttackComponent>("Attack");
	AddOwnedComponent(detection);
	AddOwnedComponent(attack);
}


void AEnnemy::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AEnnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnnemy::Init()
{
	if (!detection) return;
	aiController = Cast<ACustomAIController>(GetController());
	if (!aiController) return;
	detection.Get()->OnTargetFound().AddDynamic(aiController, &ACustomAIController::ReceiveTarget);
	detection.Get()->OnTargetDetected().AddDynamic(aiController, &ACustomAIController::ReceiveDetection);
	if (!attack) return;
	attack.Get()->OnRangeUpdate().AddDynamic(aiController, &ACustomAIController::ReceiveIsInRange);
	detection.Get()->OnTargetFound().AddDynamic(attack, &UAttackComponent::SetTarget);
}

