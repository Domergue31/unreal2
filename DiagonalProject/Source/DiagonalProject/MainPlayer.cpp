// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayer.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "Kismet/KismetSystemLibrary.h"


AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	cam = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	arm->SetupAttachment(RootComponent);
	cam->SetupAttachment(arm);
}

void AMainPlayer::InitInput()
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController();
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(context.LoadSynchronous(), 0);
}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	InitInput();
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Turn();
}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* _component = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		_component->BindAction(moveAction, ETriggerEvent::Triggered, this, &AMainPlayer::Move);
		_component->BindAction(moveAction, ETriggerEvent::Completed, this, &AMainPlayer::StopRotate);
		_component->BindAction(rotateArmAction, ETriggerEvent::Triggered, this, &AMainPlayer::RotateArm);
	}
}

void AMainPlayer::Move(const FInputActionValue& _value)
{
	FVector2D _newValue = _value.Get<FVector2D>();
	FRotator _armRotation = arm->GetRelativeRotation();
	//UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(FindAngle(_newValue)), true, true, FColor::Emerald, 1);
	//GetMesh()->SetRelativeRotation(FRotator(0,arm->GetRelativeRotation().Yaw + FindAngle(_newValue),0));
	targetYaw = FindAngle(_newValue);
	//UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(FindAngle(_newValue)), true, true, FColor::Emerald, 1);
	canRotate = true;
	AddMovementInput(GetMesh()->GetForwardVector());
}

void AMainPlayer::StopRotate(const FInputActionValue& _value)
{
	canRotate = false;
}

float AMainPlayer::FindAngle(const FVector2D& _target)
{
	FRotator _armRotation = arm->GetRelativeRotation();
	FVector2D _rotation = FVector2D(GetActorRotation().Vector());

	float _result = FMath::RadiansToDegrees(FMath::Acos(FVector2D::DotProduct(_rotation, _target) / (_rotation.Length() * _target.Length())));
	_result = FMath::IsNegative(_target.Y) && _target.Y < 0 ? -_result : _result;
	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(_result), true, true, FColor::Red, 1);
	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(_armRotation.Yaw + _result), true, true, FColor::Blue, 1);
	return _result + _armRotation.Yaw;
}

void AMainPlayer::Turn()
{
	if (!canRotate) return;
	FRotator _currentR = arm->GetRelativeRotation();
	FRotator _meshR = GetMesh()->GetRelativeRotation();
	
	//float _realYaw = FMath::Abs(_meshR.Yaw) - FMath::Abs(targetYaw) < 0 ? FMath::IsNegative(_meshR.Yaw) ? targetYaw - 360 : targetYaw + 360 : targetYaw;
	GetMesh()->SetRelativeRotation(FMath::RInterpConstantTo(_meshR, FRotator(_meshR.Pitch, targetYaw, _meshR.Roll), GetWorld()->DeltaTimeSeconds, 200));
}

void AMainPlayer::RotateArm(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	arm->AddRelativeRotation(FRotator(0, _axis, 0));
}
