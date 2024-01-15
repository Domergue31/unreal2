// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MathTester.generated.h"

UCLASS()
class AIPROJECT_API AMathTester : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere) TObjectPtr<AActor> a = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<AActor> b = nullptr;

public:	
	// Sets default values for this actor's properties
	AMathTester();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void DrawDebug();
};
