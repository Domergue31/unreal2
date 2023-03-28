// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class MARIOPROJECT_API ABlock : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:	
	ABlock();
	virtual void Active();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
