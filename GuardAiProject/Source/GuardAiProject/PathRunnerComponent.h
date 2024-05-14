// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Path.h"
#include "PathRunnerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUARDAIPROJECT_API UPathRunnerComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<APath> currentPath = nullptr;
	UPROPERTY(VisibleAnywhere) int index = 0;

	int readSpeed = 1;

public:
	FORCEINLINE void SetCurrentPath(APath* _path) { currentPath = _path; }
	FORCEINLINE void SetIndex(int _index) { index = currentPath ? FMath::Clamp(_index, 0, currentPath->Count()) : 0; }
	void Restart();
	UPathRunnerComponent();
	FVector GetPoint();
	void SetIndexPrevious();
	void SetIndexNext();
};
