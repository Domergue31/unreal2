// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CustomAIController.h"
#include "DetectionComponent.h"
#include "Components/CapsuleComponent.h"
#include "Ennemy.generated.h"



class UAttackComponent;

UCLASS()
class BTEXO_API AEnnemy : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<USkeletalMeshComponent> skeleton = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<ACustomAIController> aiController = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UDetectionComponent> detection = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UAttackComponent> attack = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UCapsuleComponent> collider = nullptr;

public:
	ACustomAIController* GetAiController() const { return aiController; }
	UDetectionComponent* GetDetection() const { return detection; }
public:
	AEnnemy();
	FORCEINLINE UAttackComponent* GetAttack() { return attack; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Init();
};
