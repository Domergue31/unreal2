// Fill out your copyright notice in the Description page of Project Settings.


#include "StarFishSpell.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values
AStarFishSpell::AStarFishSpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStarFishSpell::BeginPlay()
{
	Super::BeginPlay();
	balloffset = { GetActorForwardVector() * 50, GetActorForwardVector() * 50 + GetActorRightVector() * 50, GetActorRightVector() * 50,
									GetActorForwardVector() * -50 + GetActorRightVector() * 50, GetActorForwardVector() * -50,GetActorForwardVector() * -50 + GetActorRightVector() * -50,
									GetActorRightVector() * -50, GetActorForwardVector() * 50 + GetActorRightVector() * -50 };
	SetLifeSpan(5);
}

// Called every frame
void AStarFishSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	InvokeBall();
}

void AStarFishSpell::InvokeBall()
{
	if (hasShoot)
		return;
	for (int i = 0; i < 360; i += 45)
	{
		FRotator _rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), GetLocationFromAngle(i));
		TObjectPtr<ASphereSpell> _ball = GetWorld()->SpawnActor<ASphereSpell>(originalBall, GetLocationFromAngle(i), _rot);
	}
	hasShoot = true;
}

FVector AStarFishSpell::GetLocationFromAngle(const float& _angle) const
{
	float _rad = FMath::DegreesToRadians(_angle);
	const float _x = FMath::Cos(_rad) * radius,
		_y = FMath::Sin(_rad) * radius;
	const FVector _vector = FVector(_x, _y, 0) + GetActorLocation();
	return _vector;
}


