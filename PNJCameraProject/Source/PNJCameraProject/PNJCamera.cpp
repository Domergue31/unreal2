// Fill out your copyright notice in the Description page of Project Settings.


#include "PNJCamera.h"
#include "Kismet/KismetMathLibrary.h"
#include "PNJActor.h"

APNJCamera::APNJCamera()
{
	PrimaryActorTick.bCanEverTick = true;
}

FVector APNJCamera::FinalPosition(APNJActor* _pnj)
{
	return FVector();
}

FVector APNJCamera::GetTrigoPosition(float _radius, float _angle)
{
	const float _x = UKismetMathLibrary::Cos(_angle * UKismetMathLibrary::GetPI() / 180) * _radius,
				_y = UKismetMathLibrary::Sin(_angle * UKismetMathLibrary::GetPI() / 180) * _radius;
	return FVector(_x, _y, 0);
}
