// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LitleSpaceShip.generated.h"

USTRUCT()
struct FPosition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Location, meta = (EditCondition = "!position2 && !position3 && !position4"))
		bool position1 = true;
	UPROPERTY(EditAnywhere, Category = Location, meta = (EditCondition = "!position1 && !position3 && !position4"))
		bool position2 = false;
	UPROPERTY(EditAnywhere, Category = Location, meta = (EditCondition = "!position2 && !position1 && !position4"))
		bool position3 = false;
	UPROPERTY(EditAnywhere, Category = Location, meta = (EditCondition = "!position2 && !position3 && !position1"))
		bool position4 = false;

	FVector targetPosition;
};



UCLASS()
class ICECUBECORRECTION_API ALitleSpaceShip : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere)
		FPosition position;
	
public:	
	ALitleSpaceShip();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InitPosition();
	void ShowDebug();
	void FollowThePawn();
};
