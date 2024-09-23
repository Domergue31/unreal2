// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnTreeDataAsset.h"
#include "SpawnOctreeAsset.generated.h"

/**
 * 
 */
UCLASS()
class OCTREESUBLEVELS_API USpawnOctreeAsset : public USpawnTreeDataAsset
{
	GENERATED_BODY()

public:
	virtual void Spawn(ATreeCell* _parent) override;
	
};
