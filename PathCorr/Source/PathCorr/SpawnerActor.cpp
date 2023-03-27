// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerActor.h"
#include <Kismet/KismetMathLibrary.h>

ASpawnerActor::ASpawnerActor()
{
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
	spawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");
	spawnLocation->SetupAttachment(RootComponent);
}


void ASpawnerActor::BeginPlay()
{
	Super::BeginPlay();
	onSpawn.AddDynamic(this, &ASpawnerActor::Spawn);
	StartSpawner();
}

void ASpawnerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugBox(GetWorld(), GetSpawnLocation(), FVector(10), FColor::Blue, false, -1.0f, 0, 2);
	DrawDebugLine(GetWorld(), GetSpawnLocation(), GetActorLocation(), FColor::Blue, false, -1.0f, 0, 2);
	DrawDebugSphere(GetWorld(), GetActorLocation(), 50, 15, spawnerDebugColor, false, -1.0f, 0, 2);
	DrawDebugSphere(GetWorld(), GetSpawnLocation() + FVector(0, 0, 50), 10 * GetTimerRatio(), 15, UKismetMathLibrary::LinearColorLerp(FColor::Red, FColor::Green, GetTimerRatio()).ToFColor(true), false, -1.0f, 0, 2);
}

void ASpawnerActor::StartSpawner()
{
	if (!settings)
		return;
	GetWorldTimerManager().SetTimer(spawnerTimer, this, &ASpawnerActor::RunSpawner, settings->GetMaxTimer(), true);
	onStartSpawn.Broadcast();
	isStarted = true;
}
void ASpawnerActor::StopSpawner()
{
	GetWorldTimerManager().ClearTimer(spawnerTimer);
	onStopSpawn.Broadcast();
	isStarted = false;
}
void ASpawnerActor::RestartSpawner()
{
	StopSpawner();
	StartSpawner();
}
void ASpawnerActor::RunSpawner()
{
	onSpawn.Broadcast();
}
void ASpawnerActor::Spawn()
{
	if (!settings || !settings->GetSpawnItem())
		return;
	GetWorld()->SpawnActor<AActor>(settings->GetSpawnItem(), GetSpawnLocation(), FRotator::ZeroRotator);
	spawnCount++;
	if (settings->ClampSpawnLimit() && spawnCount >= settings->GetMaxSpawnSize())
	{
		StopSpawner();
		return;
	}
}
