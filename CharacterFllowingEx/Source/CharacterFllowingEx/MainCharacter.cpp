// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
	bUseControllerRotationYaw = true;
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Rotate", this, &AMainCharacter::RotateYaw);
	PlayerInputComponent->BindAction("Vertical", IE_Pressed, this, &AMainCharacter::ChangeFollow);
}

void AMainCharacter::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector(), _axis);
}

void AMainCharacter::RotateYaw(float _axis)
{
	AddControllerYawInput(_axis);
}

void AMainCharacter::ChangeFollow()
{
}

