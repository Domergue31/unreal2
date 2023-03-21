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
	follow = CreateDefaultSubobject<UFollowerComponent>("Follower");
	AddOwnedComponent(follow);
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (follower && isPossess)
	{
		GetWorld()->GetFirstPlayerController()->Possess(this);
		follow->SetFollowDisable();
	}
	follow->SetTarget(follower);
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
	PlayerInputComponent->BindAction("ChangeFollow", IE_Pressed, this, &AMainCharacter::ChangeFollow);
}

void AMainCharacter::MoveForward(float _axis)
{
	if (!isPossess)
		return;
	AddMovementInput(GetActorForwardVector(), _axis);
	onMoveForward.Broadcast(_axis);
	follower->OnMoveForward().Broadcast(_axis);
}

void AMainCharacter::RotateYaw(float _axis)
{
	if (!isPossess)
		return;
	AddControllerYawInput(_axis);
}

void AMainCharacter::ChangeFollow()
{
	if (!isPossess)
		return;
	isPossess = false;
	follow->SetFollowEnable();
	follower->follow->SetFollowDisable();
	follower->SetIsPossessEnable();
	onMoveForward.Broadcast(0.0f);
}

