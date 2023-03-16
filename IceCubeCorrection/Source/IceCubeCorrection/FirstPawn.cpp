// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPawn.h"
#include "Utils.h"
#include "InputUtils.h"

AFirstPawn::AFirstPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Sphere.Sphere'")));
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm = CreateDefaultSubobject< USpringArmComponent>("SpringArm");
	movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	ATTACH_TO(springArm, RootComponent);
	ATTACH_TO(camera, springArm);
	AddOwnedComponent(movement);
	//bUseControllerRotationYaw = true;
}

void AFirstPawn::BeginPlay()
{
	Super::BeginPlay();
	WORLD->GetFirstPlayerController()->SetViewTarget(this);
}

void AFirstPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFirstPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(VERTICAL, this, &AFirstPawn::MoveForward);
	PlayerInputComponent->BindAxis(HORIZONTAL, this, &AFirstPawn::MoveHorizontal);
	PlayerInputComponent->BindAxis(ROTATE, this, &AFirstPawn::RotateYaw);
}

void AFirstPawn::MoveForward(float _axis)
{
	AddMovementInput(FVector(1, 0, 0), _axis);
}

void AFirstPawn::MoveHorizontal(float _axis)
{
	AddMovementInput(FVector(0, 1, 0), _axis);
}

void AFirstPawn::RotateYaw(float _axis)
{
	AddControllerYawInput(_axis * DELTATIME);
}

