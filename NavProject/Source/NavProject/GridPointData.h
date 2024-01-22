// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GridNode.h"
#include "GridPointData.generated.h"

/**
 * 
 */
UCLASS()
class NAVPROJECT_API UGridPointData : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere) TArray<UGridNode*> nodes;

public:
	FORCEINLINE TArray<UGridNode*> Nodes() const { return nodes; }
};
