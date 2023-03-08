// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyfirstActor.generated.h"


UCLASS()
class MYFIRSTPROJECTS_API AMyfirstActor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Location")
		bool useVector = true;
	UPROPERTY(EditAnywhere, Category = "Location")
		bool useOffSet = true;
	UPROPERTY(EditAnywhere, Category = "Location")
		bool isInstantSpawn = false;
	UPROPERTY(EditAnywhere, Category = "Location")
		bool isControlBy = false;

	UPROPERTY(VisibleAnywhere, Category = "Location")
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Location", meta = (EditCondition = "useVector"))
		FVector originLocator = FVector(100);
	UPROPERTY(EditAnywhere, Category = "Location", meta = (EditCondition = "!useVector"))
		TObjectPtr<AActor> targetSpawn = nullptr;

	UPROPERTY(EditAnywhere, Category = "Location", meta = (EditCondition = "useOffSet"))
		FVector offSet = FVector(0);

	FVector fromLocation = FVector(0);

	UPROPERTY(EditAnywhere, Category = Debug)
		bool drawDebug = true;

	UPROPERTY(EditAnywhere, Category = "Location|Movement", meta = (EditCondition = "!isInstantSpawn", UIMin = 0, UIMax = 200, ClampMin = 0, ClampMax = 200))
		float speed = 100;

	UPROPERTY(EditAnywhere, Category = "Location|Movement", meta = (EditCondition = "!instantSpawn"))
		bool canMove = true;
	
public:	
	// Sets default values for this actor's properties
	AMyfirstActor();

public:
	FORCEINLINE FVector GetSpawnLocation() const
	{
		if (useVector)
			return originLocator + GetOffSet();
		else if (!useVector && targetSpawn)
			return targetSpawn->GetActorLocation() + GetOffSet();
		return GetActorLocation();
	}
	FORCEINLINE FVector GetOffSet() const { return useOffSet ? offSet : FVector(0); }
	FORCEINLINE void SetSpeed(const float& _value) { speed = _value; }
	FORCEINLINE void SetInstantSpawn(const bool& _value) { isInstantSpawn = _value; }
	FORCEINLINE void SetUseVector(const bool& _value) { useVector = _value; }
	FORCEINLINE void SetUseOffSet(const bool& _value) { useOffSet = _value; }
	FORCEINLINE void SetTarget(const TObjectPtr<AActor> _target) { targetSpawn = _target; }
	FORCEINLINE void SetCanMove(const bool& _value) { canMove = _value; }
	void MoveToLocation(const FVector& _target);
private:
	void InitObject();
	FVector GetFromPoint();
	void MoveToLocation();
	void DrawDebug();
	void MoveToLocation_Interp(const float& _speed);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
