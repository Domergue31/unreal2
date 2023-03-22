// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "MainCharacter.h"
#include "GameModeSpawn.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	AGameModeSpawn* _gm = GetWorld()->GetAuthGameMode<AGameModeSpawn>();
	_gm->GetData()->UpdateTime(GetWorld());
	//NewObject<T>(owner);
	//data = NewObject<UDataObject>(this);
	copy = GetWorld()->SpawnActor<AMainCharacter>(originalToCopy, GetActorLocation(), FRotator::ZeroRotator);
	copy->SetLifeSpan(2);
	SetLifeSpan(5);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	if (data)
		data->UpdateTime(GetWorld());
	Super::Tick(DeltaTime);

}

void AMyActor::EndPlay(const EEndPlayReason::Type)
{
	UE_LOG(LogTemp, Warning, TEXT("Je meurt"));
}

