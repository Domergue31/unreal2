#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraMovements.h"
#include "CameraManagedComponent_C.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CCC_2023_API UCameraManagedComponent_C : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<ACameraMovements> cameraSystem = nullptr;
	UPROPERTY(EditAnywhere, Category="Manager")
	FString id = "Camera";
	UPROPERTY(visibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		bool isManaged = false;
public:	
	UCameraManagedComponent_C();
	FORCEINLINE FString ID() const { return id; }
	UFUNCTION(BlueprintCallable, Category="Manager") virtual void Enable();
	UFUNCTION(BlueprintCallable, Category="Manager") virtual void Disable();
	void RegisterCamera(FString _id);
protected:
	virtual void BeginPlay() override;
	void Init();
	class UCameraManager_C* GetManager();
	ACameraMovements* GetCameraMovementSystem() const;
	UFUNCTION(BlueprintCallable, Category="Manager") void RemoveCamera();
};
