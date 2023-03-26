// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "TridusSpell.h"
#include "StarfishSpell.h"
#include "SorcererCharacter.generated.h"



UCLASS()
class FIREBALLPROJECT_API ASorcererCharacter : public ACharacter
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveForward, float, _axis);

		UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera  = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnMoveForward onMoveForward;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ATridusSpell> tridus = nullptr;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AStarFishSpell> starfish = nullptr;
	/*UPROPERTY(EditAnywhere)
		TSubclassOf<ATridusSpell> arcus = nullptr;*/
	UPROPERTY(EditAnywhere)
		TSubclassOf<ASphereSpell> ball = nullptr;



public:
	ASorcererCharacter();
	FORCEINLINE FOnMoveForward& OnMoveForward() { return onMoveForward; }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveForward(float _axis);
	void Rotate(float _axis);
	void UseTridus();
	void UseStarfish();
	void UseArcus();
};
