// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DetectObject();
}

void ATestActor::DetectObject()
{
	FHitResult _result;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 500,
		objectTypes, true, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);
	if (_hit)
	{
		FVector _reflection = GetActorForwardVector() - 2 * (FVector::DotProduct(GetActorForwardVector(), _result.ImpactNormal)) * _result.ImpactNormal;
		DrawDebugLine(GetWorld(), _result.ImpactPoint, _result.ImpactPoint + _reflection * 500, FColor::Cyan, false, -1, 0, 2);
	}
}

