// Fill out your copyright notice in the Description page of Project Settings.


#include "BooActor.h"
#include <Kismet/KismetMathLibrary.h>

ABooActor::ABooActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABooActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABooActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Follow();
}

void ABooActor::Follow()
{
	APawn* _pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), _pawn->GetActorLocation()));
	if (!IsLook())
		SetActorLocation(GetActorLocation() + GetActorForwardVector().GetSafeNormal() * GetWorld()->DeltaTimeSeconds * speed);
}

bool ABooActor::IsLook()
{
	APawn* _pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	float _result = UKismetMathLibrary::Dot_VectorVector(_pawn->GetActorForwardVector().GetSafeNormal(), GetActorForwardVector().GetSafeNormal());
	return _result < -0.85;
}

