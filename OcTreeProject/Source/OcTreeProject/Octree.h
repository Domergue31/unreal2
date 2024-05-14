// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Octree.generated.h"

class AOctreeCell;
UCLASS()
class OCTREEPROJECT_API AOctree : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TObjectPtr<AOctreeCell> root = nullptr;
	UPROPERTY(EditAnywhere) int maxBranchingID = 4;
	UPROPERTY(EditAnywhere) TSubclassOf<AOctreeCell> cellToSpawn = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess)) TObjectPtr<AActor> navMeshBoundsVolume = nullptr;
 
public:	
	FORCEINLINE TSubclassOf<AOctreeCell> GetOctreeCellToSpawn() const { return cellToSpawn; }
	FORCEINLINE int GetMaxBranchingID() const { return maxBranchingID; }

	AOctree();

	UFUNCTION(CallInEditor) void GenerateOctree();
	UFUNCTION(CallInEditor) void DestroyOctree();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;
	void InitRootCell();


};
