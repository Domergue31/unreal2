#pragma once
#include "CoreMinimal.h"

#include "CWP_Octree.h"

#include "GameFramework/Actor.h"
#include "CWP_WorldPartition.generated.h"

USTRUCT()
struct FGrid
{
	GENERATED_BODY()

	/* Name of the grid */
	UPROPERTY(EditAnywhere)
	FString name = "Unknown";

	/* Preference priority between grids */
	UPROPERTY(EditAnywhere)
	int priority = 0;

	/* Range for loading with the streaming sources */
	UPROPERTY(EditAnywhere)
	float loadingRange = 3000.0f;

	/* Size of the grid */
	UPROPERTY(EditAnywhere)
	FVector2D size = FVector2D(100.0f, 100.0f);

	/* Size of a cell */
	UPROPERTY(EditAnywhere)
	float cellSize = 100.0f;

	/* Debug settings */
	UPROPERTY(EditAnywhere)
	FDebugSettings debugSettings = FDebugSettings();
};

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_WorldPartition : public AActor
{
	GENERATED_BODY()
	
	#pragma region Values

	/* All partition grids */
	UPROPERTY(EditAnywhere, Category = "World Partition")
	FGrid grid = FGrid();

	/* The octree type to spawn */
	UPROPERTY(EditAnywhere, Category = "World Partition")
	TSubclassOf<ACWP_Octree> octreeType = TSubclassOf<ACWP_Octree>();

	/* All main octrees */
	UPROPERTY(EditAnywhere, Category = "World Partition")
	TArray<ACWP_Octree*> allOctrees = TArray<ACWP_Octree*>();

public:
	ACWP_WorldPartition();
	
private:
	UFUNCTION(CallInEditor, Category = "World Partition") void Generate();
	UFUNCTION(CallInEditor, Category = "World Partition") void SwitchVisibility();
	UFUNCTION(CallInEditor, Category = "World Partition") void Clear();
};