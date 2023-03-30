// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MobEnnemy.h"
#include "HeadMobTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API AHeadMobTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<AMobEnnemy> mob;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other);
	virtual void NotifyActorEndOverlap(AActor* _other);
};
