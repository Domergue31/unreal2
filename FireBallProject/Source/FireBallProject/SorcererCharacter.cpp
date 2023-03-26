// Fill out your copyright notice in the Description page of Project Settings.


#include "SorcererCharacter.h"

ASorcererCharacter::ASorcererCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	arm = CreateDefaultSubobject<USpringArmComponent>("Arm");
	camera->SetupAttachment(arm);
	arm->SetupAttachment(RootComponent);
	bUseControllerRotationYaw = true;
}

void ASorcererCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetFirstPlayerController()->Possess(this);
}

void ASorcererCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASorcererCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Vertical", this, &ASorcererCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Rotate", this, &ASorcererCharacter::Rotate);
	PlayerInputComponent->BindAction("TridusSpell", IE_Pressed, this, &ASorcererCharacter::UseTridus);
	PlayerInputComponent->BindAction("StarfishSpell", IE_Pressed, this, &ASorcererCharacter::UseStarfish);
}

void ASorcererCharacter::MoveForward(float _axis)
{
	AddMovementInput(GetActorForwardVector() * _axis);
	onMoveForward.Broadcast(_axis);
}

void ASorcererCharacter::Rotate(float _axis)
{
	AddControllerYawInput(_axis * 2);
}

void ASorcererCharacter::UseTridus()
{
	FVector _location = GetActorLocation() + GetActorForwardVector() * 50;
	TObjectPtr<ATridusSpell> _spell = GetWorld()->SpawnActor<ATridusSpell>(tridus, _location, GetActorRotation());
	_spell->SetOriginalBall(ball);
}

void ASorcererCharacter::UseStarfish()
{
	TObjectPtr<AStarFishSpell> _spell = GetWorld()->SpawnActor<AStarFishSpell>(starfish, GetActorLocation(), GetActorRotation());
	_spell->SetOriginalBall(ball);
}

void ASorcererCharacter::UseArcus()
{
}

