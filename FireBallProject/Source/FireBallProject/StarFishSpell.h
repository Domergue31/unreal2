// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereSpell.h"
#include "StarFishSpell.generated.h"

UCLASS()
class FIREBALLPROJECT_API AStarFishSpell : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<ASphereSpell> originalBall = nullptr;
	UPROPERTY(VisibleAnywhere)
		bool hasShoot = false;
	UPROPERTY(EditAnywhere)
		TArray<FVector> balloffset;
	UPROPERTY(EditAnywhere)
		float radius = 100;
public:	
	AStarFishSpell();
	FORCEINLINE void SetOriginalBall(TSubclassOf<ASphereSpell> _value) { originalBall = _value; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void InvokeBall();
	FVector GetLocationFromAngle(const float& _angle) const;
};
