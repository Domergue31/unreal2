// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridNode.generated.h"

/**
 * 
 */
UCLASS()
class NAVPROJECT_API UGridNode : public UObject
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere) FVector position;
	UPROPERTY(VisibleAnywhere) TArray<int> successor;
	UPROPERTY(VisibleAnywhere) TObjectPtr<class AGrid> grid = nullptr;


public:
	FORCEINLINE void SetPosition(FVector _pos) { position = _pos; }
	FORCEINLINE FVector Position() const { return position; }

	void Init(FVector _pos, AGrid* _grid);
	void AddSuccessor(int _index) { successor.Add(_index); }


	void DrawDebug(FColor _nodeColor, FColor _lineColor);
};
