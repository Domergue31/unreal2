// Fill out your copyright notice in the Description page of Project Settings.


#include "Ennemy.h"

AEnnemy::AEnnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = root;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	mesh->SetupAttachment(RootComponent);

	globalTrigger = CreateDefaultSubobject<UBoxComponent>("GlobalTrigger");
	globalTrigger->SetupAttachment(RootComponent);

	upTrigger = CreateDefaultSubobject<UBoxComponent>("UpTrigger");
	upTrigger->SetupAttachment(RootComponent);

	moveComponent = CreateDefaultSubobject<UEnemyMovingComponent>("MoveComponent");
	AddOwnedComponent(moveComponent);
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

void AEnnemy::Init()
{
	if (!globalTrigger || !upTrigger)
		return;
	globalTrigger->OnComponentBeginOverlap.AddDynamic(this, &AEnnemy::OnGlobalTrigger);
	upTrigger->OnComponentBeginOverlap.AddDynamic(this, &AEnnemy::OnUpTrigger);
}

void AEnnemy::OnGlobalTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMarioCharacter* _mario = Cast<AMarioCharacter>(OtherActor);
	if (!_mario)
		return;
	GlobalBehaviour(_mario);
}

void AEnnemy::OnUpTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMarioCharacter* _mario = Cast<AMarioCharacter>(OtherActor);
	if (!_mario)
		return;
	UpBehaviour(_mario);
}


void AEnnemy::GlobalBehaviour(AMarioCharacter* _mario)
{
}

void AEnnemy::UpBehaviour(AMarioCharacter* _mario)
{
}

void AEnnemy::Die()
{
	if (moveComponent)
		moveComponent->Stop();
}
