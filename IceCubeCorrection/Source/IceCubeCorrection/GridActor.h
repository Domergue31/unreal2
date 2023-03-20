// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

USTRUCT()
struct FGridSettingsCorr
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (UIMin = 2, ClampMin = 2))
		int size = 4;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int gap = 100;

	TArray<FVector> gridPoints;
	float minX, maxX, minY, maxY;

};
UCLASS()
class ICECUBECORRECTION_API AGridActor : public AActor
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridgenerated, AGridActor*, _grid);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGridLocation, FVector, _location);

	UPROPERTY(EditAnywhere)
		FGridSettingsCorr settings;

	FOnGridgenerated onGridGenerated;
	FOnGridLocation onGridLocation;

public:	
	AGridActor();
	FORCEINLINE FOnGridgenerated& OnGridGenerated() { return onGridGenerated; }
	FORCEINLINE FOnGridLocation& OnGridLocation() { return onGridLocation; }

	void SnapToStart(AActor* _toSnap);
	void MoveToCellDirection(AActor* _toMove, const FVector& _direction);
	void PickLocation(AActor* _target);
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Generated();
	void DrawGrid();
};
