// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioCharacter.h"


AMarioCharacter::AMarioCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMarioCharacter::BeginPlay()
{
	Super::BeginPlay();
	marioSnap = FSnapShot(GetTransform());
}

void AMarioCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMarioCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Verticale", this, &AMarioCharacter::MoveForward);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

void AMarioCharacter::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	if (_axis == 0)
		return;
	GetMesh()->SetRelativeRotation(FRotator(0, -90 * _axis, 0));
}

void AMarioCharacter::OnRespawnDelayed()
{
	marioSnap.Reload(this);
	EnableInput(GetWorld()->GetFirstPlayerController());
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetWorldTimerManager().ClearTimer(respawnDelay);
	isDead = false;
}

void AMarioCharacter::Die()
{
	isDead = true;
	DisableInput(GetWorld()->GetFirstPlayerController());
	GetWorldTimerManager().SetTimer(respawnDelay, this, &AMarioCharacter::OnRespawnDelayed, 2, true);
}