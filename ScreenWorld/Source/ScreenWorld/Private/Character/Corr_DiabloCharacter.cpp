// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Corr_DiabloCharacter.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <Kismet/KismetSystemLibrary.h>

ACorr_DiabloCharacter::ACorr_DiabloCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
}
void ACorr_DiabloCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitInput();
}
void ACorr_DiabloCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveTo(DeltaTime);
	RotateTo(DeltaTime);
}
void ACorr_DiabloCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	_input->BindAction(inputMouseAction, ETriggerEvent::Triggered, this, &ACorr_DiabloCharacter::GetTargetLocation);
}
void ACorr_DiabloCharacter::InitInput()
{
	APlayerController* _player = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(context.Get(), 0);
}
void ACorr_DiabloCharacter::MoveTo(float _delta)
{
	DrawDebugCircle(GetWorld(), destination, minRange, 15, FColor::Magenta, false, -1, 0, 5, FVector(0, 1, 0), FVector(1, 0, 0));
	DrawDebugSphere(GetWorld(), destination, 20, 15, FColor::Green, false, -1, 0, 5);
	if (IsAtLocation())
		return;
	const FVector _movement = FMath::VInterpConstantTo(GetActorLocation(), destination, _delta, GetCharacterMovement()->MaxWalkSpeed);
	FVector _direction = destination - GetActorLocation();
	AddMovementInput(_direction.GetSafeNormal(), 1);
}
void ACorr_DiabloCharacter::RotateTo(float _delta)
{
	FVector _direction = destination - GetActorLocation();
	AddControllerYawInput(FVector::DotProduct(_direction.GetSafeNormal(), GetActorRightVector()) * 2);
	//FRotator _rotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), destination);
	//_rotator.Pitch = 0;
	//_rotator.Roll = 0;
	//const FRotator _lerpRotator = FMath::RInterpConstantTo(GetActorRotation(), _rotator, _delta, 500);
	//SetActorRotation(_lerpRotator);
}
void ACorr_DiabloCharacter::GetTargetLocation()
{
	FVector _worldPosition, _worldDirection;
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(_worldPosition, _worldDirection);
	FHitResult _result;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, _worldPosition, _worldPosition + _worldDirection * 2000, interactLayer, true,
		actorIgnore, EDrawDebugTrace::None, _result, false);
	destination = _hit ? _result.ImpactPoint : destination;
}


