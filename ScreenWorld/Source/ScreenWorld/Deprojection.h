// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deprojection.generated.h"

UCLASS()
class SCREENWORLD_API ADeprojection : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category="Projection")
	TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere)
	float depth = 200;
	UPROPERTY(EditAnywhere)
	FVector2D screenLocation = FVector2D(.5f, .5f);

public:	
	ADeprojection();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void MoveTargetWithMouse();
	void MoveTargetAtViewportLocation();
};
