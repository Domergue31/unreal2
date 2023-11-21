// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Arrow.h"
#include "RicochetArrowActor.generated.h"

/**
 * 
 */
UCLASS()
class RICOCHETARROW_API ARicochetArrowActor : public AArrow
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Movement")
	TArray<FVector> path;
	
	int currentIndex = 0;

public:
	FORCEINLINE void SetPath(TArray<FVector> _path) { 
		path = _path;
		currentIndex = 0;
	}

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void Move() override;
	void ChangeCurrentIndex();
};
