// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class MARIOPROJECT_API ABlock : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBreak);
protected:
	FOnBreak onBreak;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		int maxTouch = 1;
	int actualTouch;
public:	
	ABlock();
	virtual void Active();
	FORCEINLINE FOnBreak& OnBreak() { return onBreak; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Break();
};
