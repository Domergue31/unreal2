// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigo.h"

// Sets default values
ATrigo::ATrigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

// Called when the game starts or when spawned
void ATrigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugCircle(GetWorld(), GetActorLocation(), radius, 80, FColor::Magenta, false, -1, 0, 2, FVector(1, 0, 0), FVector(0, 1, 0), true);
	for (int i = 0; i < 360; i += angle)
	{
		DrawDebugSphere(GetWorld(), GetLocationFromAngle(i),5, 10, FColor::Red);
		DrawDebugLine(GetWorld(), GetActorLocation(), GetLocationFromAngle(i), FColor::Red);
	}
}

FVector ATrigo::GetLocationFromAngle(const float& _angle) const
{
	float _rad = FMath::DegreesToRadians(_angle);
	const float _x = FMath::Cos(_rad) * radius,
		_y = FMath::Sin(_rad) * radius;
	const FVector _vector = FVector(_x, _y, 0) + GetActorLocation();
	return _vector;
}

