// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleItem.generated.h"

UCLASS()
class SCREENWORLD_API ACollectibleItem : public AActor
{
	GENERATED_BODY()
	
	int number = 1;
	UPROPERTY(EditAnywhere)
	FString name = "Bone";

public:
	FORCEINLINE int GetNumber() const { return number; }
	FORCEINLINE FString GetItemName() const { return name; }
	FORCEINLINE void SetNumber(int _number) { number = _number; }
	void AddNumber(int _number);
};
