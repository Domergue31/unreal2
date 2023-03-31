// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

ABlock::ABlock()
{
	PrimaryActorTick.bCanEverTick = true;
	blockMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = blockMesh;
	downTrigger = CreateDefaultSubobject<UBoxComponent>("DownTrigger");
	downTrigger->SetupAttachment(RootComponent);
}

void ABlock::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void ABlock::Init()
{
	if (!downTrigger)
		return;
	downTrigger->OnComponentBeginOverlap.AddDynamic(this, &ABlock::OnDownTrigger);
}

void ABlock::OnDownTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMarioCharacter* _char = Cast<AMarioCharacter>(OtherActor);
	if (!_char)
		return;
	DownBehaviour(_char);
}

void ABlock::DownBehaviour(AMarioCharacter* _char)
{

}

