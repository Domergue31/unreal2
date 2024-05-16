#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CWP_GameMode.generated.h"

class ACWP_Octree;
class ACWP_StreamManager;

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOctreeSet, ACWP_Octree*, octree);

	UPROPERTY(EditAnywhere, Category = "GameMode values")
	ACWP_Octree* octree = nullptr;

	UPROPERTY(EditAnywhere, Category = "GameMode values")
	TSoftObjectPtr<ACWP_StreamManager> stream = nullptr;

	UPROPERTY()
	FOnOctreeSet onOctreeSet = FOnOctreeSet();

public:
	UFUNCTION(BlueprintCallable) FORCEINLINE ACWP_Octree* GetOctree() const { return octree; }
	TSoftObjectPtr<ACWP_StreamManager> GetStreamManager() { return stream/*.Get()*/; }
	FORCEINLINE FOnOctreeSet* OnOctreeSet() { return &onOctreeSet; }
	FORCEINLINE void SetOctree(ACWP_Octree* _octree)
	{
		octree = _octree;
		onOctreeSet.Broadcast(octree);
	}

	void LoadLevel(const FName& _nameLevel);
	void UnloadLevel(const FName& _nameLevel);
};