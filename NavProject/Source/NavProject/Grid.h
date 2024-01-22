// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridNode.h"
#include "GridPointData.h"
#include "Grid.generated.h"

UCLASS()
class NAVPROJECT_API AGrid : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (UIMin = 2, ClampMin = 2, UMax = 10, ClampMax = 10)) int size = 4;
	UPROPERTY(EditAnywhere, meta = (UIMin = 100, ClampMin = 100, UMax = 10000, ClampMax = 10000)) int gap = 100;

	UPROPERTY(EditAnywhere) FColor nodeColor = FColor::Green;
	UPROPERTY(EditAnywhere) FColor lineColor = FColor::Red;

	UPROPERTY(EditAnywhere) bool useDebug = true;
	UPROPERTY(VisibleAnywhere) TArray<UGridNode*> nodes;
	UPROPERTY(EditAnywhere) TObjectPtr<UGridPointData> data = nullptr;
public:
	AGrid();
	FORCEINLINE TArray<UGridNode*> Nodes() const { return nodes; }
protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(CallInEditor, Category="Spawn Grid") void Generate();
	UFUNCTION(CallInEditor, Category = "Spawn Grid") void ClearGrid();

	void SetSuccessor();
	void DrawNodes();

	virtual bool ShouldTickIfViewportsOnly() const override;
};
