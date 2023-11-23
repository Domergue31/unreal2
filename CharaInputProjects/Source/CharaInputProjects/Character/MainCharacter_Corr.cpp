// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter_Corr.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include <EnhancedInputSubsystems.h>

AMainCharacter_Corr::AMainCharacter_Corr()
{
	PrimaryActorTick.bCanEverTick = true;
	interact = CreateDefaultSubobject<UInteractComponent>("Interaction");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	AddOwnedComponent(interact);
	camera->SetupAttachment(arm);
	arm->SetupAttachment(RootComponent);
}

void AMainCharacter_Corr::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacter_Corr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter_Corr::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (!inputsConfig)
		return;
	inputsConfig->EnableInputContext(Cast<APlayerController>(GetWorld()->GetFirstPlayerController())->GetLocalPlayer());
	UEnhancedInputComponent* _input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	_input->BindAction(inputsConfig->ForwardInput(), ETriggerEvent::Triggered, this, &AMainCharacter_Corr::MoveForward);
	_input->BindAction(inputsConfig->ForwardInput(), ETriggerEvent::Completed, this, &AMainCharacter_Corr::ReleaseForward);
	_input->BindAction(inputsConfig->RotateInput(), ETriggerEvent::Triggered, this, &AMainCharacter_Corr::RotateCharacter);
	_input->BindAction(inputsConfig->InteractInput(), ETriggerEvent::Completed, interact.Get(), &UInteractComponent::DropObject);
	_input->BindAction(inputsConfig->InteractInput(), ETriggerEvent::Completed, interact.Get(), &UInteractComponent::GrabObject);
}

void AMainCharacter_Corr::MoveForward(const FInputActionValue& _value)
{
	float _from, _to;
	responseCurve->GetTimeRange(_from, _to);
	TimeX = FMath::Lerp(_from, _to, GetWorld()->DeltaTimeSeconds);
	axis = _value.Get<float>() - responseCurve->GetFloatValue(TimeX);
	AddMovementInput(GetActorForwardVector(), axis);
}

void AMainCharacter_Corr::ReleaseForward(const FInputActionValue& _value)
{
	TimeX = 0;
	axis = 0;
}

void AMainCharacter_Corr::RotateCharacter(const FInputActionValue& _value)
{
	AddControllerYawInput(_value.Get<float>() * GetWorld()->DeltaTimeSeconds * rotationSpeed);
}


