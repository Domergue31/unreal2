// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnInputExample.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include <Kismet/KismetSystemLibrary.h>

APawnInputExample::APawnInputExample()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}
void APawnInputExample::InitInputSystem()
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController();
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player->GetLocalPlayer());
	_inputSystem->ClearAllMappings();
	//inputContext.Get();
	_inputSystem->AddMappingContext(inputContext.LoadSynchronous(), 0);
}

void APawnInputExample::BeginPlay()
{
	Super::BeginPlay();
	InitInputSystem();
}

void APawnInputExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APawnInputExample::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* _input = Cast< UEnhancedInputComponent>(PlayerInputComponent);
	_input->BindAction(movementInputs, ETriggerEvent::Triggered, this, &APawnInputExample::MoveForwardTest);
}

void APawnInputExample::MoveForwardTest(const FInputActionValue& _value)
{
	const float _axis = _value.Get<float>();
	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(_axis));
}

