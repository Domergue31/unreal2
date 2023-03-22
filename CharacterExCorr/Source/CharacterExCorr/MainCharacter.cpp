// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Kismet/KismetMathlibrary.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
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
	FollowBehaviour();
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Rotate", this, &AMainCharacter::Rotate);
}

void AMainCharacter::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	onMoveForward.Broadcast(_axis);
}

void AMainCharacter::Rotate(float _axis)
{
	AddControllerYawInput(_axis);
}

void AMainCharacter::FollowBehaviour()
{
	if (isControl || !GetWorld()->GetFirstPlayerController() || !GetWorld()->GetFirstPlayerController()->GetPawn())
		return;
	const FVector _this = GetActorLocation(),
		_other = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
					
	const bool _isAtRange = settings.IsAtRange(_this, _other);
	onMoveForward.Broadcast(_isAtRange ? 0 : 1);
	if (_isAtRange)
		return;
	const FVector _location = FMath::VInterpConstantTo(_this, _other, GetWorld()->DeltaTimeSeconds, settings.speed);
	SetActorLocation(_location);
	const FRotator _rotation = UKismetMathLibrary::FindLookAtRotation(_this, _other);
	SetActorRotation(_rotation);
}

