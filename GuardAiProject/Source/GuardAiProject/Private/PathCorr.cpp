// Fill out your copyright notice in the Description page of Project Settings.


#include "PathCorr.h"

APathCorr::APathCorr()
{
	PrimaryActorTick.bCanEverTick = true;
	spline = CreateDefaultSubobject<USplineComponent>("Spline");
	RootComponent = spline;
}

void APathCorr::BeginPlay()
{
	Super::BeginPlay();
	InitSplineLine();
}

void APathCorr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetSecondLine();
	GetIntersectionPoint(lineA, lineB, intersectPoint);
	lineA.DrawLine(GetWorld(),FColor::Red);
	lineB.DrawLine(GetWorld(),FColor::Red);
	DrawDebugSphere(GetWorld(), intersectPoint, 10, 20, FColor::Magenta, false, -1, 0, 2);
	DrawDebugSphere(GetWorld(), GetSplinePoint(), 10, 20, FColor::Magenta, false, -1, 0, 2);
}

void APathCorr::InitSplineLine()
{
	lineA.Point = GetActorLocation();
	lineA.End = spline->GetLocationAtTime(1, ESplineCoordinateSpace::World);
}
void APathCorr::SetSecondLine()
{
	if (!target)
		return;
	lineB.Point = target->GetActorLocation();
	lineB.End = lineB.Point + target->GetActorForwardVector() * 500;
}
FVector APathCorr::GetSplinePoint()
{
	const float _from = FVector::Dist(lineA.Point, intersectPoint);
	const float _to = FVector::Dist(lineA.Point, lineA.End);
	const float _alpha = _from / _to;
	return spline->GetLocationAtTime(_alpha, ESplineCoordinateSpace::World);
}
void APathCorr::GetIntersectionPoint(FLine _a, FLine _b, FVector& _intersectPoint)
{
	FVector _lineAB = _b.Point - _a.Point;
	FVector _crossAB = FVector::CrossProduct(_a.GetDirection(), _b.GetDirection());
	const FVector _crossLineAB = FVector::CrossProduct(_lineAB, _b.GetDirection());
	float _dot = FVector::DotProduct(_lineAB, _crossAB);
	if (FMath::Abs(_dot) < 0.0001f && _crossAB.SizeSquared() > 0.0001f)
	{
		float _angle = FVector::DotProduct(_crossLineAB, _crossAB) / _crossAB.SizeSquared();
		_intersectPoint = _a.Point + (_a.GetDirection() * _angle);
	}
	else
		_intersectPoint = FVector::ZeroVector;
}

