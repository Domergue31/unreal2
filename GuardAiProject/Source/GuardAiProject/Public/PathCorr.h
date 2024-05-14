// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "PathCorr.generated.h"

USTRUCT()
struct FLine
{
	GENERATED_BODY()
public:
	FVector Point, End;
	FORCEINLINE FVector GetDirection() const { return (End - Point).GetSafeNormal(); }
	FORCEINLINE void DrawLine(UWorld* _world, const FColor& _color)
	{
		DrawDebugLine(_world, Point, End, _color, false, -1, 0, 3);
	}
};


UCLASS()
class GUARDAIPROJECT_API APathCorr : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<USplineComponent> spline = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<AActor> target = nullptr;
	FVector intersectPoint;
	FLine lineA, lineB;
public:	
	APathCorr();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitSplineLine();
	void SetSecondLine();
	FVector GetSplinePoint();
	void GetIntersectionPoint(FLine _a, FLine _b, FVector& _intersectPoint);
};
