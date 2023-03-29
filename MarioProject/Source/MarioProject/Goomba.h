// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MobEnnemy.h"
#include "Goomba.generated.h"

UCLASS()
class MARIOPROJECT_API AGoomba : public AMobEnnemy
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float direction = 1.0f;
	
public:	
	AGoomba();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other) override;
	void Move();
	virtual void Hit() override;
};
