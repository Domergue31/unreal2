// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetCorrection.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API APlanetCorrection : public AActor
{
	GENERATED_BODY()

		FVector initScale;
		float initDistance = 1000;

		UPROPERTY(EditAnywhere, Category = Planet)
			bool useRandomScale = true;

		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	
public:	
	// Sets default values for this actor's properties
	APlanetCorrection();
	FORCEINLINE float GetCurrentDistanceTo(const FVector& _from) { return FVector::Distance(_from, GetActorLocation()); }
	FORCEINLINE float GetMaxDistance() const { return initDistance; }
	FORCEINLINE void SetInitDistance(const FVector& _shipLocation) { initDistance = GetCurrentDistanceTo(_shipLocation); }
	void UpdateSize(const FVector& _location);
private:
	void InitPlanet();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
