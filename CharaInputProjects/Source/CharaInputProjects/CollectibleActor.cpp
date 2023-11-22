// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleActor.h"

// Sets default values
ACollectibleActor::ACollectibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACollectibleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectibleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

