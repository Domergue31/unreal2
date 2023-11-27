

#include "MainPlayer.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include <Kismet/KismetSystemLibrary.h>

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	arm->SetupAttachment(RootComponent);
	camera->SetupAttachment(arm);
}

void AMainPlayer::InitInput()
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController<APlayerController>();
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(inputContext.LoadSynchronous(), 0);
}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	InitInput();
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	_input->BindAction(forwardInput, ETriggerEvent::Triggered, this, &AMainPlayer::MoveForward);
	_input->BindAction(forwardInput, ETriggerEvent::Canceled, this, &AMainPlayer::MoveForward);
	_input->BindAction(rightInput, ETriggerEvent::Triggered, this, &AMainPlayer::MoveRight);
	_input->BindAction(cameraYawInput, ETriggerEvent::Triggered, this, &AMainPlayer::RotateCameraYaw);
	_input->BindAction(cameraPitchInput, ETriggerEvent::Triggered, this, &AMainPlayer::RotateCameraPitch);
	_input->BindAction(takePLaceObjectInput, ETriggerEvent::Triggered, this, &AMainPlayer::InteractCollectibleObject);
	_input->BindAction(JumpInput, ETriggerEvent::Triggered, this, &AMainPlayer::StartJump);
}

void AMainPlayer::MoveForward(const FInputActionValue& _value)
{
	const float _axis = _value.Get<float>();
	AddMovementInput(GetActorForwardVector() * movementSpeed, _axis);
	if (objectTaken)
		objectTaken->SetActorLocation(GetActorLocation() + GetActorForwardVector() * 100);
	onForwardMove.Broadcast(_axis);
}
void AMainPlayer::MoveRight(const FInputActionValue& _value)
{
	const float _axis = _value.Get<float>();
	AddMovementInput(GetActorRightVector() * movementSpeed, _axis);
	if (objectTaken)
		objectTaken->SetActorLocation(GetActorLocation() + GetActorForwardVector() * 100);
	onRightMove.Broadcast(_axis);
}
void AMainPlayer::RotateCameraYaw(const FInputActionValue& _value)
{
	const float _axis = _value.Get<float>();
	AddControllerYawInput(_axis * cameraYawSpeed);
	if (objectTaken)
		objectTaken->SetActorLocation(GetActorLocation() + GetActorForwardVector() * 100);
}
void AMainPlayer::RotateCameraPitch(const FInputActionValue& _value)
{
	const float _axis = _value.Get<float>();
	FRotator _newRot = arm->GetRelativeRotation() + FRotator(-_axis * cameraPitchSpeed, 0, 0);
	arm->SetRelativeRotation(_newRot);
}

void AMainPlayer::InteractCollectibleObject(const FInputActionValue& _value)
{
	if (objectTaken && CanPlaceObject())
	{
		objectTaken = nullptr;
		return;
	}
	objectTaken = IsObjectInFront();
	if (objectTaken)
		objectTaken->SetActorLocation(GetActorLocation() + GetActorForwardVector() * 100);

}

AActor* AMainPlayer::IsObjectInFront()
{
	FHitResult _result;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100,
		takeObjetcType, true, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);
	if (_hit)
		return _result.GetActor();
	return nullptr;
}

void AMainPlayer::StartJump(const FInputActionValue& _value)
{
	Jump();
	onJump.Broadcast(true);
}

bool AMainPlayer::CanPlaceObject()
{
	FHitResult _result;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100,
		placeObjectsType, true, TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);
	if (_hit)
		return false;
	return true;
}

