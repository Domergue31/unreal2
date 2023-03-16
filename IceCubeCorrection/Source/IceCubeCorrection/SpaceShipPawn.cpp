// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShipPawn.h"
#include "Utils.h"
#include "inputUtils.h"

ASpaceShipPawn::ASpaceShipPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	ATTACH_TO(springArm, RootComponent);
	ATTACH_TO(camera, springArm);
	AddOwnedComponent(movement);
}

void ASpaceShipPawn::BeginPlay()
{
	Super::BeginPlay();
	WORLD->GetFirstPlayerController()->SetViewTarget(this);
}

void ASpaceShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpaceShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &ASpaceShipPawn::MoveForward);
	PlayerInputComponent->BindAxis(ROTATEPITCH, this, &ASpaceShipPawn::RotatePitch);
	PlayerInputComponent->BindAxis(ROTATE, this, &ASpaceShipPawn::RotateRoll);
}




void ASpaceShipPawn::MoveForward(float _axis)
{
	settings.fwdAxis = LERP(settings.fwdAxis, FMath::Abs(_axis), DELTATIME * settings.fwdWeight);
	settings.shipVelocity = GetActorForwardVector() * settings.fwdAxis;
	AddMovementInput(settings.shipVelocity * 1.1);
}

void ASpaceShipPawn::RotatePitch(float _axis)
{
	settings.pitchAxis = LERP(settings.pitchAxis, _axis, DELTATIME * settings.rotateWeight);
	const FRotator _newPitch = LERP(GetActorRotation(), FRotator(bankPitchAngle * settings.pitchAxis, GetActorRotation().Yaw, 0), DELTATIME * settings.pitchSpeed);
	SetActorRotation(_newPitch);
}

void ASpaceShipPawn::RotateRoll(float _axis)
{
	settings.yawAxis = LERP(settings.yawAxis, _axis, DELTATIME * settings.rotateWeight);
	AddControllerYawInput(settings.yawAxis * DELTATIME * settings.rotaSpeed);
	const FRotator _bank = LERP(GetActorRotation(), FRotator(0, GetActorRotation().Yaw, bankAngle * settings.yawAxis), DELTATIME * settings.rotaSpeed);
	SetActorRotation(_bank);


}