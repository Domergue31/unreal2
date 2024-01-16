// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Waypoint.h"
#include "Path.generated.h"

UCLASS()
class GUARDAIPROJECT_API APath : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TArray<AWaypoint*> points = {};
	UPROPERTY(EditAnywhere) TObjectPtr<UBillboardComponent> icon = nullptr;
public:	
	FORCEINLINE AWaypoint* GetAt(int _n) const { return points[_n]; }
	FORCEINLINE int Count() const { return points.Num(); }
	APath();
	AWaypoint* GetStartingPoint() const;
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void DrawPath();
	virtual bool ShouldTickIfViewportsOnly() const override;
};
