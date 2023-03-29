// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mobsettings.h"
#include "MobEnnemy.generated.h"

UCLASS()
class MARIOPROJECT_API AMobEnnemy : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
		TObjectPtr<UMobSettings> settings = nullptr;
	UPROPERTY(VisibleAnywhere)
		int actualLife;
public:	
	AMobEnnemy();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other);
	virtual void Hit();
};
