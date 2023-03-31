// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BooActor.generated.h"

UCLASS()
class MARIOCORR_API ABooActor : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		float speed = 100;
public:	
	ABooActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Follow();
	bool IsLook();
};
