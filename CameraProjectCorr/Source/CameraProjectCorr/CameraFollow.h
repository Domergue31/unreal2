#pragma once

#include "CoreMinimal.h"
#include "CameraMovement.h"
#include "CameraFollow.generated.h"

UCLASS()
class CAMERAPROJECTCORR_API ACameraFollow : public ACameraMovement
{
	GENERATED_BODY()
	

public:
	FORCEINLINE virtual FVector Offset() const override
	{
		return GetLocalOffset(0,0,0);
	}
protected:
	virtual void UpdateCameraPosition() override;
	virtual void DrawDebug() override;
};
