// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyMovingComponent.h"
#include "Components/BoxComponent.h"
#include "MarioCharacter.h"
#include "Ennemy.generated.h"

UCLASS()
class MARIOCORR_API AEnnemy : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<USceneComponent> root = nullptr;
		UPROPERTY(EditAnywhere)
		TObjectPtr<UBoxComponent> globalTrigger = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UBoxComponent> upTrigger = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
protected:
	UPROPERTY(EditAnywhere)
		TObjectPtr<UEnemyMovingComponent> moveComponent = nullptr;

	bool isDead = false;
public:	
	AEnnemy();

private:
	UFUNCTION() void OnGlobalTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
	UFUNCTION() void OnUpTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
protected:
	void Init();
	virtual void GlobalBehaviour(AMarioCharacter* _mario);
	virtual void UpBehaviour(AMarioCharacter* _mario);
	virtual void Die();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
