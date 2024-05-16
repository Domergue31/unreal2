
#include "CWP_MovementComponent.h"

UCWP_MovementComponent::UCWP_MovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCWP_MovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCWP_MovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCWP_MovementComponent::Move(const FInputActionValue& _value)
{
	if (!canMove) return;

	const FVector2D& _movementValue = _value.Get<FVector2D>();
	const float _speed = (isSprinting ? sprintSpeed * 100.0f : moveSpeed * 10.0f) * GetWorld()->DeltaTimeSeconds;

	APawn* _pawn = GetPawn();
	_pawn->AddMovementInput(_pawn->GetActorRightVector(), _movementValue.X * _speed);
	_pawn->AddMovementInput(_pawn->GetActorForwardVector(), _movementValue.Y * _speed);
}

void UCWP_MovementComponent::Sprint(const FInputActionValue& _value)
{
	isSprinting = _value.Get<bool>();
}

void UCWP_MovementComponent::Rotate(const FInputActionValue& _value)
{
	if (!canRotate) return;

	const FVector2D& _rotationValue = _value.Get<FVector2D>();
	APawn* _pawn = GetPawn();
	_pawn->AddControllerYawInput(_rotationValue.X);
	_pawn->AddControllerPitchInput(_rotationValue.Y);
}