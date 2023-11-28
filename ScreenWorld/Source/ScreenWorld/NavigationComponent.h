// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputMappingContext.h"
#include "NavigationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCREENWORLD_API UNavigationComponent : public UActorComponent
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMove, float, _axis);

	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnMove onMove;

	UPROPERTY(EditAnywhere, Category="LineTrace")
	TArray<TEnumAsByte<EObjectTypeQuery>> clickedMask;
	UPROPERTY(EditAnywhere, Category="LineTrace")
	TArray<TEnumAsByte<EObjectTypeQuery>> moveMask;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
	float speed = 100;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess))
	bool canMove = false;

	FVector targetLocation;
	FRotator lookAt;


public:
	FORCEINLINE FOnMove& OnMove() { return onMove; }
	FORCEINLINE FVector GetOwnerLocation() const { return GetOwner()->GetActorLocation(); }
	FORCEINLINE void SetOwnerLocation(FVector _location) { GetOwner()->SetActorLocation(_location); }
	UNavigationComponent();

	UFUNCTION() void Clicked();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool LocationClicked();
	bool CanGo(FVector _targetPosition);

	void Move();
	void SetRotation();
	bool IsAtDestination(FVector _a, FVector _b);

	void DrawDebug();
};
