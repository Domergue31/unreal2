// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trigo.generated.h"

UCLASS()
class FIREBALLPROJECT_API ATrigo : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		float angle = 45;
	UPROPERTY(EditAnywhere)
		float radius = 100;


public:	
	// Sets default values for this actor's properties
	ATrigo();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	FVector GetLocationFromAngle(const float& _angle) const;
};
