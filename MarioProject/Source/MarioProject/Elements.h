// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elements.generated.h"

UCLASS()
class MARIOPROJECT_API AElements : public AActor
{
	GENERATED_BODY()
	
public:	
	AElements();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* _other);
};
