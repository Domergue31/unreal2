// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereSpell.h"
#include "TridusSpell.generated.h"

UCLASS()
class FIREBALLPROJECT_API ATridusSpell : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		TSubclassOf<ASphereSpell> originalBall = nullptr;
	UPROPERTY(VisibleAnywhere)
		bool hasShoot = false;
	UPROPERTY(EditAnywhere)
		float radius = 100;
public:	
	ATridusSpell();
	FORCEINLINE void SetOriginalBall(TSubclassOf<ASphereSpell> _value) { originalBall = _value; }
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void InvokeBall();
	FVector GetLocationFromAngle(const float& _angle) const;
};
