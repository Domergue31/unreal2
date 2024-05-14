// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "OctreeCell.generated.h"



USTRUCT()
struct FOctreeCellParameter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) int childrenNumberToSpawn = 8;
	UPROPERTY(EditAnywhere) int capacity = 0;
};


class AOctree;
UCLASS()
class OCTREEPROJECT_API AOctreeCell : public AActor
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumberOfActorInsideUpdate, int, _numberOfActorInside);

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnNumberOfActorInsideUpdate onNumberOfActorInsideUpdate;

	UPROPERTY(EditAnywhere) int branchingID = 1;
	UPROPERTY(EditAnywhere, Category="OctreeCell|Internal") TObjectPtr<AOctree> octree = nullptr;
	UPROPERTY(EditAnywhere,Category = "OctreeCell|Internal") TObjectPtr<AOctreeCell> parent = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UBoxComponent> box = nullptr;
	UPROPERTY(EditAnywhere, Category = "OctreeCell|Internal") FOctreeCellParameter cellParameters = FOctreeCellParameter();

	UPROPERTY(EditAnywhere, Category = "OctreeCell|Internal") TArray<AOctreeCell*> cellChildren;
	UPROPERTY(EditAnywhere) bool IsActive = true;

	UPROPERTY(EditAnywhere) TArray<TSubclassOf<AActor>> classToDetect;
	UPROPERTY(EditAnywhere) TArray<AActor*> actorsInside = {};
	UPROPERTY(EditAnywhere, Category = "OctreeCell|Internal") int currentActorsInside = 0;
	UPROPERTY(EditAnywhere, Category = "OctreeCell|Internal") int currentNumberOfChildren = 0;

	UPROPERTY(EditAnywhere, Category = "OctreeCell|Debug") bool useDebug = false;
	UPROPERTY(EditAnywhere, Category = "OctreeCell|Debug") bool debugArea = false;
	UPROPERTY(EditAnywhere, Category = "OctreeCell|Debug", meta = (EditCondition = "useDebug", EditConditionHide)) int debugThickness = 2;
	UPROPERTY(EditAnywhere, Category = "OctreeCell|Debug", meta = (EditCondition = "useDebug")) FColor debugColor = FColor::Blue;



public:
	FORCEINLINE FOnNumberOfActorInsideUpdate& OnNumberOfActorInsideUpdate() { return onNumberOfActorInsideUpdate; }
	AOctreeCell();

	void SetOctree(AOctree* _octree);
	void SetCellDimensions(const double _length, const double _width, const double _height);
	void SetCellDimensions(const FVector& _dimensions);
	void CustomDestroy();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	void InitSubCell(const int _branchingID, AOctree* _octree, AOctreeCell* _parent);
	void SubDivideCells(const FVector _subLocation);
	void RemoveSubCells();
	UFUNCTION() void ManageCellBehaviour(const int _numberOfActorsInside);
	FVector GetSubLocation(const int _index);
	void DrawDebug();
};
