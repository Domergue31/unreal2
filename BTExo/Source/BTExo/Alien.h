// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AICharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AlienSightSystemComponent.h"
#include "CustomAIController.h"
#include "Alien.generated.h"

UCLASS()
class BTEXO_API AAlien : public AAICharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere) TObjectPtr<UAlienSightSystemComponent> sight = nullptr;

	FTimerHandle sightTimer;

public:
	AAlien();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Detect();
};
