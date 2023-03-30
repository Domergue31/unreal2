// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Elements.h"
#include "Spells.h"
#include "FlamesFlower.generated.h"

/**
 * 
 */
UCLASS()
class MARIOPROJECT_API AFlamesFlower : public AElements
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpells> fireBall = nullptr;
public:
	AFlamesFlower();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other) override;
};
