// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereSpell.generated.h"

UCLASS()
class FIREBALLPROJECT_API ASphereSpell : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		float speed = 200.0f;
public:	
	ASphereSpell();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Move();
};
