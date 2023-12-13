
#include "MainPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	fpsCamera = CreateDefaultSubobject<UCameraComponent>("FPS Camera");
	tpsCamera = CreateDefaultSubobject<UCameraComponent>("TPS Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	arm->SetupAttachment(RootComponent);
	tpsCamera->SetupAttachment(arm);
	fpsCamera->SetupAttachment(RootComponent);
}

void AMainPlayer::InitInputs()
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController<APlayerController>();
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(context.LoadSynchronous(), 0);
}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	InitInputs();
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _inputs = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	_inputs->BindAction(moveVertical, ETriggerEvent::Triggered, this, &AMainPlayer::MoveVertical);
	_inputs->BindAction(moveHorizontal, ETriggerEvent::Triggered, this, &AMainPlayer::MoveHorizontal);
	_inputs->BindAction(rotateYaw, ETriggerEvent::Triggered, this, &AMainPlayer::RotateYaw);
	_inputs->BindAction(rotatePitch, ETriggerEvent::Triggered, this, &AMainPlayer::RotateCameraPitch);
}

void AMainPlayer::MoveVertical(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	AddMovementInput(GetActorForwardVector() * verticalSpeed, _axis);
}

void AMainPlayer::MoveHorizontal(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	AddMovementInput(GetActorRightVector() * horizontalSpeed, _axis);
}

void AMainPlayer::RotateYaw(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	AddControllerYawInput(_axis);
}

void AMainPlayer::RotateCameraPitch(const FInputActionValue& _value)
{
	float _axis = _value.Get<float>();
	FRotator _rot = fpsCamera->GetRelativeRotation();
	fpsCamera->SetRelativeRotation(FRotator(FMath::Clamp(_rot.Pitch + _axis, -80, 80), _rot.Yaw, _rot.Roll));
}

