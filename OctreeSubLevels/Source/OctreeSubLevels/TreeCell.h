// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TreeComponent.h"
#include "SpawnTreeDataAsset.h"
#include "TreeCell.generated.h"

USTRUCT()
struct FDebugSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool useDebug = false;
	UPROPERTY(EditAnywhere, meta = (UMin = 1, ClampMin = 1, UMax = 1000, ClampMax = 1000))
	float thickness = 1;
	UPROPERTY(EditAnywhere)
	FColor debugColor = FColor::Blue;
};

UCLASS()
class OCTREESUBLEVELS_API ATreeCell : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="Tree|DataValues")
	bool isMaster = false;
	UPROPERTY(EditAnywhere, Category="Tree|DataValues", meta=(UMin=1, ClampMin=1, EditCondition = "isMaster", EditConditionHides))
	int splitMinQty = 5;
	UPROPERTY(VisibleAnywhere, Category="Tree|DataValues")
	int subStep = 1;
	UPROPERTY(EditAnywhere, Category="Tree|DataValues", meta=(UMin=1, ClampMin=1, EditCondition = "isMaster", EditConditionHides))
	TArray<TEnumAsByte<EObjectTypeQuery>> octreeMask;

	UPROPERTY(EditAnywhere, Category = "Tree|DataValues", meta = (EditCondition = "isMaster"))
	TObjectPtr<USpawnTreeDataAsset> spawnAsset = nullptr;

	UPROPERTY(EditAnywhere, Category="Tree|DataValues", meta=(EditCondition="isMaster", EditConditionHides))
	FVector boxScale = FVector(100);
	UPROPERTY(VisibleAnywhere, Category="Tree|DataValues")
	FBox cellBox;
	UPROPERTY(EditAnywhere, Category="Tree")
	FDebugSettings debugSettings;

	UPROPERTY(VisibleAnywhere, Category = "Tree|DataValues", meta = (EditCondition = "!isMaster", EditConditionHides))
	TObjectPtr<ATreeCell> master = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Tree|DataValues", meta = (EditCondition = "!isMaster", EditConditionHides))
	TArray<ATreeCell*> treeChilds;
	UPROPERTY(VisibleAnywhere, Category = "Tree|DataValues", meta = (EditCondition = "isMaster", EditConditionHides))
	TArray<ATreeCell*> allTreeLeaves;
	UPROPERTY(VisibleAnywhere, Category="Tree|DataValues")
	TObjectPtr<UWorld> subLevel = nullptr;
	UPROPERTY(VisibleAnywhere, Category="Tree|DataValues")
	TArray<UTreeComponent*> allActorsComponents;

public:
	FORCEINLINE void AddTreeLeaves(TObjectPtr<ATreeCell> _treeCell) { allTreeLeaves.Add(_treeCell); }
	FORCEINLINE void AddChildTree(TObjectPtr<ATreeCell> _treeCell) { treeChilds.Add(_treeCell); }

	FORCEINLINE FBox GetCellBox() const { return cellBox; }
	FORCEINLINE int GetSubStep() const { return subStep; }
	FORCEINLINE bool IsMaster() const { return isMaster; }
	FORCEINLINE ATreeCell* GetMaster() {
		if (isMaster)
			return this;
		else
			return master; }
	FORCEINLINE int GetSpliMinQty() const { return splitMinQty; }
	FORCEINLINE TArray<UTreeComponent*> GetAllActorsComponent() { return allActorsComponents; }
	ATreeCell();

	UFUNCTION(CallInEditor, Category="Octree Action") void UpdateTree();

	void SetupTree(ATreeCell* _master, const int _splitMinQty, const int _subStep, const FBox& _box, TArray<UTreeComponent*> _comps);

	void SwitchSubLevelState(const bool _state);
	void AddActorToLevel(AActor* _actor);
	void RemoveActorOfLevel(AActor* _actor);
protected:

	virtual void Tick(float _deltaTime) override;
	virtual void OnConstruction(const FTransform& _transform) override;
#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	bool ShouldTickIfViewportsOnly() const override;
#endif

private:
	void DrawOctreeBox() const;
	TArray<UTreeComponent*> GetActorsComponentInBox();
	void SpawnChildren();
	bool SpawnSubLevel();
};
