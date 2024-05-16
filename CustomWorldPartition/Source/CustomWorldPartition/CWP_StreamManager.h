#pragma once
#include "CoreMinimal.h"
#include "CWP_StreamingSourceComponent.h"
#include "GameFramework/Actor.h"
#include "CWP_StreamManager.generated.h"

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_StreamManager : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Stream")
	TArray<UCWP_StreamingSourceComponent*> allSourcesComponent;

	UPROPERTY(VisibleAnywhere, Category = "Streaming")
	ACWP_Octree* octree;

private:
	UFUNCTION() FORCEINLINE void SetOctree(ACWP_Octree* _octree)
	{
		octree = _octree;
	}
public:
	FORCEINLINE void Register(UCWP_StreamingSourceComponent* _streaming)
	{
		if (allSourcesComponent.Contains(_streaming)) return;
		allSourcesComponent.Add(_streaming);
	}

public:
	ACWP_StreamManager();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Update();
};