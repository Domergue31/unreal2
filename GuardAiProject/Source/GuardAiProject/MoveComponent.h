// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GUARDAIPROJECT_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) FVector destination;
	UPROPERTY(EditAnywhere, meta = (UMin = 0, ClampMin = 0)) float speed = 5;
	UPROPERTY(EditAnywhere) float range = 100;

	bool canMove = false;

public:	
	UMoveComponent();
	UFUNCTION(BlueprintCallable) FORCEINLINE void SetDestination(FVector _newDest) { destination = FVector(_newDest.X, _newDest.Y, GetOwner()->GetActorLocation().Z); }
	UFUNCTION(BlueprintCallable) FORCEINLINE bool IsAtDestination() const { return FVector::Distance(GetOwner()->GetActorLocation(), destination) <= range; }
	FORCEINLINE void SetCanMove(bool _state) { canMove = _state; }
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UpdateMovement();
};
