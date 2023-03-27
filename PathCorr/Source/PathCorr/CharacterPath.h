// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Gameframework/SpringArmComponent.h"
#include "CharacterPath.generated.h"

UCLASS()
class PATHCORR_API ACharacterPath : public ACharacter
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<class UFollowPathComponent> follow = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<USpringArmComponent> arm = nullptr;

public:
	ACharacterPath();
	void ControlCharacter();
	void FreeCharacter();
protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	TObjectPtr<class APawnSwitcher> GetPawnManager();
	void MoveForward(float _axis);
	void Rotate(float _axis);
};
