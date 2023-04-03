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
	initSize = GetActorScale();
	powerUpTargetSize = initSize * 1.5f;
	ReloadDatas();
}

void AMarioCharacter::ReloadDatas()
{
	if (saveData)
		saveData->LoadCharacter(this);
	if (hasPowerUp)
		AddPowerUp();

}

void AMarioCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PowerUpEffect();
	ShrinkEffect();
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
	{
		onMove.Broadcast(_axis);
		return;
	}
	GetMesh()->SetRelativeRotation(FRotator(0, -90 * _axis, 0));
	onMove.Broadcast(_axis);
}

void AMarioCharacter::OnRespawnDelayed()
{
	marioSnap.Reload(this);
	EnableInput(GetWorld()->GetFirstPlayerController());
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetWorldTimerManager().ClearTimer(respawnDelay);
	isDead = false;
}

void AMarioCharacter::PowerUpEffect()
{
	if (!startPowerUpEffect || startShrinkEffect)
		return;
	powerUpTimer += GetWorld()->DeltaTimeSeconds * .8f;
	startPowerUpEffect = powerUpTimer < 1;
	SetActorScale3D(FMath::Lerp(initSize, powerUpTargetSize, powerUpTimer));
	if (powerUpTimer >= 1)
	{
		EnableInput(GetWorld()->GetFirstPlayerController());
		powerUpTimer = 0;
	}
}

void AMarioCharacter::ShrinkEffect()
{
	if (!startShrinkEffect)
		return;
	powerUpTimer += GetWorld()->DeltaTimeSeconds * .8f;
	startShrinkEffect = powerUpTimer < 1;
	SetActorScale3D(FMath::Lerp(powerUpTargetSize, initSize, powerUpTimer));
	if (powerUpTimer >= 1)
	{
		EnableInput(GetWorld()->GetFirstPlayerController());
		powerUpTimer = 0;
	}
}

void AMarioCharacter::Die()
{
	if (hasPowerUp)
	{
		startShrinkEffect = true;
		hasPowerUp = false;
		if (saveData)
			saveData->SavedCharacter(this);
		return;
	}
	isDead = true;
	DisableInput(GetWorld()->GetFirstPlayerController());
	GetWorldTimerManager().SetTimer(respawnDelay, this, &AMarioCharacter::OnRespawnDelayed, 2, true);
}

void AMarioCharacter::AddPowerUp()
{
	hasPowerUp = true;
	startPowerUpEffect = true;
	onMove.Broadcast(0);
	DisableInput(GetWorld()->GetFirstPlayerController());
	if (saveData)
		saveData->SavedCharacter(this);
}
