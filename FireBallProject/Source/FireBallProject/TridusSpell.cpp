// Fill out your copyright notice in the Description page of Project Settings.


#include "TridusSpell.h"
#include <Kismet/KismetMathLibrary.h>

ATridusSpell::ATridusSpell()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void ATridusSpell::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(5);
}

void ATridusSpell::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	InvokeBall();
}

void ATridusSpell::InvokeBall()
{
	if (hasShoot)
		return;
	for (int i = 0; i < 360; i += 45)
	{
		TObjectPtr<ASphereSpell> _ball = GetWorld()->SpawnActor<ASphereSpell>(originalBall, GetLocationFromAngle(i), GetActorRotation());
	}
	hasShoot = true;
}

FVector ATridusSpell::GetLocationFromAngle(const float& _angle) const
{
	float _rad = FMath::DegreesToRadians(_angle);
	const float _x = FMath::Cos(_rad) * radius,
		_y = FMath::Sin(_rad) * radius;
	const FVector _vector = FVector(_x, _y, 0) + GetActorLocation();
	return _vector;
}