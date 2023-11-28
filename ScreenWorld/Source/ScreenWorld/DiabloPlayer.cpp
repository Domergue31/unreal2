// Fill out your copyright notice in the Description page of Project Settings.


#include "DiabloPlayer.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


ADiabloPlayer::ADiabloPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	nav = CreateDefaultSubobject<UNavigationComponent>("Navigation Component");

	camera->SetupAttachment(arm);
	arm->SetupAttachment(RootComponent);
	AddOwnedComponent(nav);
}

void ADiabloPlayer::InitInput()
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController<APlayerController>();
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(context.LoadSynchronous(), 0);
}

void ADiabloPlayer::BeginPlay()
{
	Super::BeginPlay();
	inv = NewObject<UInventory>(this, inventoryRef);
	InitInput();
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}

void ADiabloPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADiabloPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	


	_input->BindAction(click, ETriggerEvent::Triggered, this, &ADiabloPlayer::Move);
	onClick.AddDynamic(nav, &UNavigationComponent::Clicked);
}

void ADiabloPlayer::Move(const FInputActionValue& _value)
{
	if (_value.Get<bool>())
		onClick.Broadcast();
}

