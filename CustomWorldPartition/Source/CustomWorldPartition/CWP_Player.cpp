#include "CWP_Player.h"
#include "CWP_MovementComponent.h"
#include "CWP_SightComponent.h"
#include "CWP_StreamingSourceComponent.h"
#include "CWP_StreamManagerSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

ACWP_Player::ACWP_Player()
{
	PrimaryActorTick.bCanEverTick = true;

	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	camera->SetupAttachment(GetMesh());

	movement = CreateDefaultSubobject<UCWP_MovementComponent>("Movement");
	AddOwnedComponent(movement);

	sight = CreateDefaultSubobject<UCWP_SightComponent>("Sight");
	AddOwnedComponent(sight);
	
	streamingSource = CreateDefaultSubobject<UCWP_StreamingSourceComponent>("StreamingSource");
	AddOwnedComponent(streamingSource);
}

void ACWP_Player::BeginPlay()
{
	Super::BeginPlay(); 
	InitInputs();
	UKismetSystemLibrary::PrintString(this, "Playe Begin", true, true, FLinearColor::Blue, 5);
	if (!Controller)
	{
		if (UCWP_StreamManagerSubsystem* _manager = GetWorld()->GetSubsystem<UCWP_StreamManagerSubsystem>())
		{
			_manager->Unregister(streamingSource);
		}
	}
}

void ACWP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACWP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* _inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Movement
		_inputComponent->BindAction(inputs.movement, ETriggerEvent::Triggered, movement.Get(), &UCWP_MovementComponent::Move);
		_inputComponent->BindAction(inputs.movement, ETriggerEvent::Completed, movement.Get(), &UCWP_MovementComponent::Move);

		// Sprint
		_inputComponent->BindAction(inputs.sprint, ETriggerEvent::Triggered, movement.Get(), &UCWP_MovementComponent::Sprint);
		_inputComponent->BindAction(inputs.sprint, ETriggerEvent::Completed, movement.Get(), &UCWP_MovementComponent::Sprint);

		// Rotate
		_inputComponent->BindAction(inputs.rotation, ETriggerEvent::Triggered, movement.Get(), &UCWP_MovementComponent::Rotate);
	}
	else
	{
		LOG_S("%s Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file.", GetNameSafe(this));
	}
}


void ACWP_Player::InitInputs()
{
	if (APlayerController* _playerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_playerController->GetLocalPlayer()))
		{
			_inputSystem->AddMappingContext(inputs.inputMapping, 0);
		}
	}
}