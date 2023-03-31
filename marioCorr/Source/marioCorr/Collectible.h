// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MarioCharacter.h"
#include "Collectible.generated.h"

UCLASS()
class MARIOCORR_API ACollectible : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UBoxComponent> trigger = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:	
	ACollectible();

protected:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* _other);
protected:
	virtual void CollectibleBehaviour(AMarioCharacter* _mario);
};
