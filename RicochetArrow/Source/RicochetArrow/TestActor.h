// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class RICOCHETARROW_API ATestActor : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="LineTrace")
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;


public:	
	ATestActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DetectObject();
};
