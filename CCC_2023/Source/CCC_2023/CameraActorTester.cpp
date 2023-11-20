// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraActorTester.h"
#include "MainGameMode.h"
#include "CameraManager_C.h"

// Sets default values
ACameraActorTester::ACameraActorTester()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

// Called when the game starts or when spawned
void ACameraActorTester::BeginPlay()
{
	Super::BeginPlay();
	AMainGameMode* _gm = GetWorld()->GetAuthGameMode <AMainGameMode>();
	_gm->CameraManager()->SpawnOrbitCamera("test", this);
}

// Called every frame
void ACameraActorTester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

