// Fill out your copyright notice in the Description page of Project Settings.


#include "MathTester.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "MathUtils.h"

// Sets default values
AMathTester::AMathTester()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

// Called when the game starts or when spawned
void AMathTester::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMathTester::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FVector _directionA = a->GetActorLocation() - GetActorLocation();
	//FVector _directionB = b->GetActorLocation() - GetActorLocation();
	//UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(MathUtils::Angle(_directionA.GetSafeNormal(), _directionB.GetSafeNormal())));
	DrawDebug();
}

void AMathTester::DrawDebug()
{
	if (!a || !b) return;
	DrawDebugSphere(GetWorld(), a->GetActorLocation(), 50, 20, FColor::Red, false, -1, 0, 2);
	DrawDebugSphere(GetWorld(), b->GetActorLocation(), 50, 20, FColor::Red, false, -1, 0, 2);

	DrawDebugLine(GetWorld(), GetActorLocation(), a->GetActorLocation(), FColor::Yellow, false, -1, 0, 2);
	DrawDebugLine(GetWorld(), GetActorLocation(), b->GetActorLocation(), FColor::Yellow, false, -1, 0, 2);
}

