// Fill out your copyright notice in the Description page of Project Settings.


#include "GridPawn.h"
#include "Utils.h"
#include "InputUtils.h"

AGridPawn::AGridPawn()
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
}

void AGridPawn::BeginPlay()
{
	Super::BeginPlay();
    follower;
}

void AGridPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAction(UP, EInputEvent::IE_Pressed, this, &AGridPawn::MoveUp);
    PlayerInputComponent->BindAction(DOWN, EInputEvent::IE_Pressed, this, &AGridPawn::MoveDown);
    PlayerInputComponent->BindAction(RIGHT, EInputEvent::IE_Pressed, this, &AGridPawn::MoveRight);
    PlayerInputComponent->BindAction(LEFT, EInputEvent::IE_Pressed, this, &AGridPawn::MoveLeft);
}

void AGridPawn::MoveUp()
{
    grid->MoveUp();
}

void AGridPawn::MoveDown()
{
    grid->MoveDown();
}

void AGridPawn::MoveRight()
{
    grid->MoveRight();
}

void AGridPawn::MoveLeft()
{
    grid->MoveLeft();
}

