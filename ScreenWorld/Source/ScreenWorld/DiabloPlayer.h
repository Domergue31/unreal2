// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "Inventory.h"
#include "NavigationComponent.h"
#include "DiabloPlayer.generated.h"

UCLASS()
class SCREENWORLD_API ADiabloPlayer : public ACharacter
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClick);


	UPROPERTY(BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
	FOnClick onClick;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditANywhere)
	TObjectPtr<USpringArmComponent> arm = nullptr;
	UPROPERTY(EditANywhere)
	TObjectPtr<UNavigationComponent> nav = nullptr;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UInventory> inventoryRef = nullptr;

	UPROPERTY()
	TObjectPtr<UInventory> inv = nullptr;

	UPROPERTY(EditAnywhere, Category = "Inputs")
	TSoftObjectPtr<UInputMappingContext> context = nullptr;
	UPROPERTY(EditAnywhere, Category = "Inputs")
	TObjectPtr<UInputAction> click = nullptr;

public:
	FORCEINLINE FOnClick& OnClick() { return onClick; }
	FORCEINLINE UNavigationComponent* Navigation() { return nav; }
	FORCEINLINE TObjectPtr<UInventory> Inventory() { return inv; }
	ADiabloPlayer();

protected:
	void InitInput();
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& _value);

};
