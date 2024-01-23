// Fill out your copyright notice in the Description page of Project Settings.


#include "MathUtils.h"
#include "Kismet/KismetMathLibrary.h"

MathUtils::MathUtils()
{
}

MathUtils::~MathUtils()
{
}

float MathUtils::Angle(FVector _a, FVector _b) 
{
	const float _rad = FVector::DotProduct(_a, _b) / (_a.Size() * _b.Size());
	return FMath::Acos(_rad) / (UKismetMathLibrary::GetPI() / 180);
}
