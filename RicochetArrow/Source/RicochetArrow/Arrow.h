// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

UCLASS()
class RICOCHETARROW_API AArrow : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere, Category="Speed", meta = (UIMin = 0.1f, ClampMin = 0.1f))
	float speed = 100;
public:	
	AArrow();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void Move();
};
