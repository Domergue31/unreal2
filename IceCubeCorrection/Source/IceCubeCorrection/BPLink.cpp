// Fill out your copyright notice in the Description page of Project Settings.


#include "BPLink.h"
#include "Utils.h"

// Sets default values
ABPLink::ABPLink()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABPLink::BeginPlay()
{
	Super::BeginPlay();
	onTest.Broadcast();
}

// Called every frame
void ABPLink::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABPLink::Test()
{
	LOG_W(LogTemp, "Test");
}

void ABPLink::TestParam(float _value)
{
	LOG_W(LogTemp, "Test %f", _value);

}

