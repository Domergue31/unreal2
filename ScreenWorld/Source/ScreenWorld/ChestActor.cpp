// Fill out your copyright notice in the Description page of Project Settings.


#include "ChestActor.h"
#include <Kismet/KismetSystemLibrary.h>

AChestActor::AChestActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	triggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	RootComponent = mesh;
	triggerBox->SetupAttachment(RootComponent);
}

void AChestActor::BeginPlay()
{
	Super::BeginPlay();
	triggerBox->OnComponentBeginOverlap.AddDynamic(this, &AChestActor::OnEnterTrigger);
}

void AChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChestActor::OnEnterTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADiabloPlayer* _player = Cast<ADiabloPlayer>(OtherActor);
	if (_player)
		EnterBehaviour(_player);
}

void AChestActor::EnterBehaviour(ADiabloPlayer* _player)
{
	ACollectibleItem* _item = NewObject<ACollectibleItem>(this, item);
	_item->SetNumber(number);
	_player->Inventory()->Add(_item);
	Destroy();
}

