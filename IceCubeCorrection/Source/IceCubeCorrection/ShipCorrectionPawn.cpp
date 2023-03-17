// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipCorrectionPawn.h"
#include "Utils.h"
#include "InputUtils.h"


AShipCorrectionPawn::AShipCorrectionPawn()
{
	PrimaryActorTick.bCanEverTick = true;
    mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    movement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
    grid = CreateDefaultSubobject<UGridComponent>("Grid");
    RootComponent = mesh;
    ATTACH_TO(springArm, RootComponent);
    ATTACH_TO(camera, springArm);
    AddOwnedComponent(movement);
    AddOwnedComponent(grid);
    bUseControllerRotationYaw = true;
}

void AShipCorrectionPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShipCorrectionPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    DRAW_SPHERE(GetActorLocation() + GetVelocity().GetClampedToMaxSize(100), 5, FColor::Yellow, 2);
    DRAW_LINE(GetActorLocation(), (GetActorLocation() + GetVelocity().GetClampedToMaxSize(100)), FColor::Yellow, 2);
}

void AShipCorrectionPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis(VERTICAL, this, &AShipCorrectionPawn::MoveForward);
    PlayerInputComponent->BindAxis(HORIZONTAL, this, &AShipCorrectionPawn::RollMovement);
    PlayerInputComponent->BindAxis(HORIZONTAL, this, &AShipCorrectionPawn::YawMovement);
    PlayerInputComponent->BindAction(UP, EInputEvent::IE_Pressed, grid.Get(), &UGridComponent::MoveUp);
    PlayerInputComponent->BindAction(DOWN, EInputEvent::IE_Pressed, grid.Get(), &UGridComponent::MoveDown);
    PlayerInputComponent->BindAction(RIGHT, EInputEvent::IE_Pressed, grid.Get(), &UGridComponent::MoveRight);
    PlayerInputComponent->BindAction(LEFT, EInputEvent::IE_Pressed, grid.Get(), &UGridComponent::MoveLeft);
}

void AShipCorrectionPawn::MoveForward(float _axis)
{
    if (_axis < 0)
        return;
    settings.forwardAxis = FMath::Lerp(settings.forwardAxis, _axis, DELTATIME * (1 / settings.forwardWeight));
    AddMovementInput(GetActorForwardVector(), settings.forwardAxis);
}
void AShipCorrectionPawn::RollMovement(float _axis)
{
    settings.rollAxis = FMath::Lerp(settings.rollAxis, _axis, DELTATIME * (1 / settings.rollWeight));
    SetActorRotation(FRotator(0, 0, settings.maxAngle * settings.rollAxis));
}
void AShipCorrectionPawn::YawMovement(float _axis)
{
    settings.yawAxis = FMath::Lerp(settings.yawAxis, _axis, DELTATIME * (1 / settings.yawWeight));
    AddControllerYawInput(settings.yawAxis);
}