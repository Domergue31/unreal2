#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraManagedComponent.h"
#include "CameraManager.generated.h"

UCLASS()
class CCC_2023_API ACameraManager : public AActor
{
	GENERATED_BODY()
	TMap<FString, UCameraManagedComponent*> items = TMap<FString, UCameraManagedComponent*>();

public:	
	ACameraManager();

	void Register(UCameraManagedComponent* _camera);
	void UnRegister(UCameraManagedComponent* _camera);

};
