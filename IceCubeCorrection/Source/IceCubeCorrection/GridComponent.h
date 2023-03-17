// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridComponent.generated.h"

USTRUCT()
struct FGridSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int verticalLine = 4;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, ClampMin = 1))
		int horizontalLine = 4;

	FVector startLocation;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBECORRECTION_API UGridComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGridSettings settings;
	/*UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> */


public:	
	UGridComponent();
	FORCEINLINE void SetTarget(FVector _start) { settings.startLocation = _start; }
	FORCEINLINE FVector GetActorLocation() const { return GetOwner()->GetActorLocation(); }
	FORCEINLINE void SetActorLocation(FVector _location) { GetOwner()->SetActorLocation(_location); }
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ShowGrid();
		
};
