#pragma once
#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "CWP_CustomWorldSettings.generated.h"

UCLASS()
class CUSTOMWORLDPARTITION_API ACWP_CustomWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="StreamingManagerSubsystem", meta = (UMin = 0, ClampMin = 0))
	float baseHeight = 5000.0f;

	UPROPERTY(EditAnywhere, Category="StreamingManagerSubsystem", meta = (UMin = 0, ClampMin = 0))
	float depthScale = 0.8f;

	UPROPERTY(EditAnywhere, Category = "SubLevelsData")
	FName subLevelName = "";

	//UPROPERTY(EditAnywhere, Category = "SubLevelsData")
	//TAray<TSoftObjectPtr<UWorld>> subLevels;

public:
	float GetBaseHeight() const { return baseHeight; }
	float GetDepthScale() const { return depthScale; }

protected:
	virtual void BeginPlay() override;
};