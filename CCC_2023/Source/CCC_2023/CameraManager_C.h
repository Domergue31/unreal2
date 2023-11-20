// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Kismet/KismetSystemLibrary.h>
#include "CameraManagedComponent_C.h"
#include "CameraFollow.h"
#include "OrbitCamera.h"
#include "CameraManager_C.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CCC_2023_API UCameraManager_C : public UObject
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	TMap<FString, UCameraManagedComponent_C*> cameras;

	UPROPERTY(EditAnywhere, Category="Manager")
	TSubclassOf<ACameraFollow> cameraFollowDefault = nullptr;
	UPROPERTY(EditAnywhere, Category="Manager")
	TSubclassOf<AOrbitCamera> orbitCameradefault = nullptr;

public:
	bool AddCamera(UCameraManagedComponent_C* _camera);
	bool RemoveCamera(UCameraManagedComponent_C* _camera);

	UFUNCTION(BlueprintCallable) void DisableCamera(FString _id);
	UFUNCTION(BlueprintCallable) void EnableCamera(FString _id);
	UFUNCTION(BlueprintCallable) void SpawnCameraFollow(FString _id, AActor* _target);
	UFUNCTION(BlueprintCallable) void SpawnOrbitCamera(FString _id, AActor* _target);
	template <class T>
	T* SpawnCamera(TSubclassOf<T> _subclass, FString _id, AActor* _target)
	{
		T* _instance = GetWorld()->SpawnActor<T>(_subclass);
		_instance->SetTarget(_target);
		UCameraManagedComponent_C* _component = _instance->GetComponentByClass<UCameraManagedComponent_C>();
		if (_component)
			_component->RegisterCamera(_id);
		return _instance;
	}
};
