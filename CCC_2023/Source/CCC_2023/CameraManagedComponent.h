#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraManagedComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CCC_2023_API UCameraManagedComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category="Managed")
	FString cameraID = "camera";

public:	
	UCameraManagedComponent();
	FORCEINLINE FString GetCameraID() const { return cameraID; }
protected:
	virtual void BeginPlay() override;

		
};
