// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GridActor.h"
#include "MoveOnGridComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ICECUBECORRECTION_API UMoveOnGridComponent : public UActorComponent
{
	GENERATED_BODY()

		UPROPERTY(Editanywhere)
		TObjectPtr<AGridActor> grid = nullptr;
	UPROPERTY(EditAnywhere)
		FVector offset = FVector(0, 0, 100);

	FVector targetLocation;

public:	
	UMoveOnGridComponent();

private:
	void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	UFUNCTION() void SetLocation(FVector _location);
	void MoveToLocation();
	void LookAtDirection();
};
