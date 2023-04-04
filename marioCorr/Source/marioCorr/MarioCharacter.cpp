// Fill out your copyright notice in the Description page of Project Settings.


#include "MarioCharacter.h"


AMarioCharacter::AMarioCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMarioCharacter::BeginPlay()
{
	Super::BeginPlay();
	jumpLastLocation = GetActorLocation();
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
		SetActorScale3D(powerUpTargetSize);

}

void AMarioCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PowerUpEffect();
	ShrinkEffect();
	VerifyJump();
}

void AMarioCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Verticale", this, &AMarioCharacter::MoveForward);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("QuitGame", IE_Pressed, this, &AMarioCharacter::QuitGame);
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

void AMarioCharacter::QuitGame()
{
	if (!levelLoadData)
		return;
	levelLoadData->LoadLevel(GetWorld());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);

}

void AMarioCharacter::OnRespawnDelayed()
{
	marioSnap.Reload(this);
	EnableInput(GetWorld()->GetFirstPlayerController());
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	GetWorldTimerManager().ClearTimer(respawnDelay);
	isDead = false;
	onDie.Broadcast(0);
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
		SetActorScale3D(powerUpTargetSize);
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

void AMarioCharacter::VerifyJump()
{
	FVector _actualLocation = GetActorLocation();
	if (startShrinkEffect || startPowerUpEffect)
	{
		onJump.Broadcast(0);
		jumpLastLocation = _actualLocation;
		return;
	}
	if (_actualLocation.Z > jumpLastLocation.Z)
		onJump.Broadcast(1);
	else if (_actualLocation.Z < jumpLastLocation.Z)
		onJump.Broadcast(1);
	else if (_actualLocation.Z == jumpLastLocation.Z)
		onJump.Broadcast(0);
	jumpLastLocation = _actualLocation;
}

void AMarioCharacter::Die()
{
	if (isDead || startShrinkEffect)
		return;
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
	GetWorldTimerManager().SetTimer(respawnDelay, this, &AMarioCharacter::OnRespawnDelayed, 3, true);
	onDie.Broadcast(1);
}

void AMarioCharacter::AddPowerUp()
{
	if (GetActorScale() == powerUpTargetSize)
		return;
	MoveForward(0);
	hasPowerUp = true;
	startPowerUpEffect = true;
	DisableInput(GetWorld()->GetFirstPlayerController());
	if (saveData)
		saveData->SavedCharacter(this);
}
