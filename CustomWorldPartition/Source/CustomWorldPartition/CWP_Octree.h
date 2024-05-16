#pragma once
#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Actor.h"
#include "CWP_Octree.generated.h"

USTRUCT()
struct FDebugSettings
{
	GENERATED_BODY()

	/* Status of debugs */
	UPROPERTY(EditAnywhere, Category = "Octree values | Debug")
	bool showDebug = true;

	/* Thickness of the box's lines when debugs are enabled */
	UPROPERTY(EditAnywhere, Category = "Octree values | Debug")
	float thickness = 200.0f;

	/* Box color when debugs are enabled */
	UPROPERTY(EditAnywhere, Category = "Octree values | Debug")
	FColor lineColor = FColor::Cyan;
};

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_Octree : public AActor
{
	GENERATED_BODY()
	
	#pragma region Values

	/* Box color when debugs are enabled */
	UPROPERTY(EditAnywhere, Category = "Octree values | Debug")
	FDebugSettings debugSettings = FDebugSettings();

	/* Precision of this octree */
	UPROPERTY(EditAnywhere, Category = "Octree values | Data")
	bool isMaster = false;

	UPROPERTY(VisibleAnywhere, Category = "Octree values | Data")
	int accuracy = 1;

	/* Capacity min this octree can contains */
	UPROPERTY(VisibleAnywhere, Category = "Octree values | Data")
	int capacityMin = 1;

	/* Capacity max this octree can contains */
	UPROPERTY(EditAnywhere, Category = "Octree values | Data", meta = (ClampMin = "1", ClampMax = "10000"))
	int capacity = 50;

	/* Box scale */
	UPROPERTY(EditAnywhere, Category = "Octree values | Data")
	FVector boxScale = FVector(100.0f);

	/* Box container */
	UPROPERTY(VisibleAnywhere, Category = "Octree values | Data")
	FBox box = FBox();

	/* Type to octree to spawn */
	UPROPERTY(EditAnywhere, Category = "Octree values | Data")
	TSubclassOf<ACWP_Octree> octreeType = TSubclassOf<ACWP_Octree>();

	/* All actors to ignore */
	UPROPERTY(EditAnywhere, Category = "Octree values | Data")
	TArray<TSoftObjectPtr<AActor>> actorsToIgnore = TArray<TSoftObjectPtr<AActor>>();

	/* List of all actors contains */
	UPROPERTY(VisibleAnywhere, Category = "Octree values | Data")
	TArray<TSoftObjectPtr<AActor>> actors = TArray<TSoftObjectPtr<AActor>>();

	#pragma endregion

	#pragma region Pointers

	/* Master of all octrees */
	UPROPERTY()
	ACWP_Octree* master = nullptr;

	/* List of all children */
	UPROPERTY()
	TArray<ACWP_Octree*> octreeChildren = TArray<ACWP_Octree*>();

	/* List of all octree without children */
	UPROPERTY()
	TArray<ACWP_Octree*> octreesWithoutChildren = TArray<ACWP_Octree*>();

	#pragma endregion 

public:
	#pragma region Setters

	/* Initialize a child */
	FORCEINLINE void Setup(const int& _accuracy, const int& _capacity, const FBox& _boundingBox, ACWP_Octree* _master, const TArray<TSoftObjectPtr<AActor>>& _actors)
	{
		accuracy = _accuracy;
		capacity = _capacity;
		box = _boundingBox;
		master = _master;
		actors = _actors;
	}

	/* Store a new octree without children */
	FORCEINLINE void AddOctreeWithoutChildren(ACWP_Octree* _octree) { octreesWithoutChildren.Add(_octree); }

	#pragma endregion

	#pragma region Getters

	/* Ask if this octree has children */
	FORCEINLINE bool HasChildren() const { return octreeChildren.Num() > 0; }

	/* Get the box container */
	FORCEINLINE const FBox& GetBox() const { return box; }

	/* Get all octrees without children */
	FORCEINLINE const TArray<ACWP_Octree*>& GetOctreesWithoutChildren() const { return octreesWithoutChildren; }

	/* Get all actors contained into the octree */
	FORCEINLINE TArray<TSoftObjectPtr<AActor>> GetAllActors() const { return actors; }

	#pragma endregion	

public:
	ACWP_Octree();

	#pragma region Methods

	#pragma region Engine
private:
	virtual void OnConstruction(const FTransform& _transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float _deltaTime) override;
#if WITH_EDITOR
	virtual bool ShouldTickIfViewportsOnly() const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& _event) override;
#endif

	#pragma endregion 

	#pragma region Tool

public:
	/* Update actors and possible children octree */
	UFUNCTION(CallInEditor, Category = "Octree actions") void Update();

	/* Deactivate all octree's debugs */
	UFUNCTION(CallInEditor, Category = "Octree actions") void SwitchVisibility();

	/* Reset all actors (= only for the main) and children */
	UFUNCTION(CallInEditor, Category = "Octree actions") void Clear();

	#pragma endregion

	#pragma region Common

	/* Draw current octree */
	void DrawOctrees() const;

	/* Get all actors which is into the octree */
	void GetActors();

	/* Check if the current actor has a StaticMeshComponent */
	bool HasStaticMesh(AActor* _actor);

	/* Spawn and setup 8 children */
	void SpawnChildren();

	/* Destroy all children */
	void ResetOctree();

	#pragma endregion

	#pragma region Public

public:
	void ChangeVisibility(const bool _status);
	void Place(const FVector& _location, const float _size);

	#pragma endregion

	#pragma endregion 
};