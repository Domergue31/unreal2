// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "CollectibleItem.h"
#include "DiabloPlayer.h"
#include "ChestActor.generated.h"

UCLASS()
class SCREENWORLD_API AChestActor : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> triggerBox = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> mesh = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACollectibleItem> item = nullptr;

	UPROPERTY(EditAnywhere, meta = (UIMin = 0, ClampMin = 0))
	int number = 1;

public:	
	AChestActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION() void OnEnterTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void EnterBehaviour(ADiabloPlayer* _player);
};
