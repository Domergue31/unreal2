// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPath.h"
#include "PathCorrGameModeBase.h"
#include "FollowPathComponent.h"

// Sets default values
ACharacterPath::ACharacterPath()
{
	PrimaryActorTick.bCanEverTick = true;
	follow = CreateDefaultSubobject<UFollowPathComponent>("Follow");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera->SetupAttachment(arm);
	arm->SetupAttachment(RootComponent);
	AddOwnedComponent(follow);
}

void ACharacterPath::ControlCharacter()
{
	if (follow)
		follow->StopFollow();
	bUseControllerRotationYaw = true;
}

void ACharacterPath::FreeCharacter()
{
	if (follow)
		follow->StartFollow();
	bUseControllerRotationYaw = false;
}

void ACharacterPath::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetPawnManager()->RemovePawn(this);
}

void ACharacterPath::BeginPlay()
{
	Super::BeginPlay();
	APawnSwitcher* _switcher = GetPawnManager();
	if (!_switcher)
		return;
	_switcher->AddPawn(this);
}

void ACharacterPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterPath::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &ACharacterPath::MoveForward);
	PlayerInputComponent->BindAxis("Rotate", this, &ACharacterPath::Rotate);
}

TObjectPtr<APawnSwitcher> ACharacterPath::GetPawnManager()
{
	APathCorrGameModeBase* _gm = GetWorld()->GetAuthGameMode<APathCorrGameModeBase>();
	if (!_gm)
		return nullptr;
	return _gm->GetPawnManager();
}

void ACharacterPath::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector(), _axis);
}

void ACharacterPath::Rotate(float _axis)
{
	AddControllerYawInput(_axis);
}
