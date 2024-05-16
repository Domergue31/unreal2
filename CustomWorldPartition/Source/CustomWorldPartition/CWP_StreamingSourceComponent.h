#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CWP_StreamingSourceComponent.generated.h"

class ACWP_Octree;

UCLASS( ClassGroup=(Custom), meta = (BlueprintSpawnableComponent) )
class CUSTOMWORLDPARTITION_API UCWP_StreamingSourceComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Streaming", meta = (ClampMin = "0.0", ClampMax = "100000"))
	float radius = 1000.0f;

public:	
	UCWP_StreamingSourceComponent();

private:
	virtual void BeginPlay() override;

public:
	/*UFUNCTION()*/ TArray<ACWP_Octree*> UpdateStreaming(ACWP_Octree* _octreeMaster);
};