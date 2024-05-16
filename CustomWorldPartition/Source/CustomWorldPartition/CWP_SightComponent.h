#pragma once
#include "CoreMinimal.h"
#include "CWP_Octree.h"
#include "Components/ActorComponent.h"
#include "CWP_SightComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta = (BlueprintSpawnableComponent) )
class CUSTOMWORLDPARTITION_API UCWP_SightComponent : public UActorComponent
{
	GENERATED_BODY()

	#pragma region Values

	/* Should it use range for checking */
	UPROPERTY(EditAnywhere, Category = "Frutum checker values")
	bool bUseRange = true;

	/* Range of checker detection */
	UPROPERTY(EditAnywhere, Category = "Frutum checker values", meta = (UIMin = "0.0", UIMax = "100000.0", ClampMin = "0.0", ClampMax = "100000.0",
		EditCondition = "bUseRange", EditConditionHides))
	float fRange = 500.0f;

	/* Rate of the detection */
	UPROPERTY(EditAnywhere, Category = "Frutum checker values", meta = (UIMin = "0.1", UIMax = "60.0", ClampMin = "0.1", ClampMax = "60.0"))
	float fCheckRate = 0.1f;

	/* Scale of the detection */
	UPROPERTY(EditAnywhere, Category = "Frutum checker values", meta = (UIMin = "0.1", UIMax = "1000.0", ClampMin = "0.1", ClampMax = "1000.0"))
	float fCheckScale = 10.0f;

	#pragma endregion

	#pragma region Pointers

	/* Current world */
	UPROPERTY()
	UWorld* world = nullptr;

	/* Current octree */
	UPROPERTY()
	ACWP_Octree* octree = nullptr;

	/* Current local player */
	UPROPERTY()
	ULocalPlayer* localPlayer = nullptr;

	/* Current viewportClient */
	UPROPERTY()
	TObjectPtr<UGameViewportClient> viewportClient = nullptr;

	/* Current SceneView */
	FSceneView* sceneView = nullptr;

	/* Current viewport */
	FViewport* viewport = nullptr;

#pragma endregion

public:	
	UCWP_SightComponent();

private:
	virtual void BeginPlay() override;
	
	/* When the octree is set, start a timer for checking method */
	UFUNCTION() void InitTimer(ACWP_Octree* _octree);

	/* Run through all actors contained into the current octree */
	UFUNCTION() void CheckVisibility();

	/* Update the current scene view of the renderer */
	void UpdateSceneView();

	/* Check if the current actor volume is into the camera's frustum */
	bool IsInFrustum(const AActor* _target) const;
};