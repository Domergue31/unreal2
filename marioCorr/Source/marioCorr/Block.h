// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MarioCharacter.h"
#include "Block.generated.h"

UCLASS()
class MARIOCORR_API ABlock : public AActor
{
protected:
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> blockMesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UBoxComponent> downTrigger = nullptr;
public:
	ABlock();

protected:
	virtual void BeginPlay() override;
	void Init();
	UFUNCTION() void OnDownTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void DownBehaviour(AMarioCharacter* _char);
};
