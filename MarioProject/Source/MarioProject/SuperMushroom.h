// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Elements.h"
#include "SuperMushroom.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API ASuperMushroom : public AElements
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		float direction = 2.0f;
	UPROPERTY(EditAnywhere)
		float speed = 100.0f;
public:
	ASuperMushroom();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other) override;
	void ChangeDirection();
};
