// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <Kismet/KismetSystemLibrary.h>

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
}


void AMainCharacter::InitInput()
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController<APlayerController>();
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(context.LoadSynchronous(), 0);
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitInput();
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	_input->BindAction(move, ETriggerEvent::Triggered, this, &AMainCharacter::Move);
	_input->BindAction(rotateYaw, ETriggerEvent::Triggered, this, &AMainCharacter::RotateYaw);
}

void AMainCharacter::Move(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	AddMovementInput(GetActorForwardVector() * moveSpeed, _axis);
	onMove.Broadcast(_axis);
}

void AMainCharacter::RotateYaw(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	AddControllerYawInput(_axis * rotateSpeed);
}

