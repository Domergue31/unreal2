// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnCorrection.h"
#include "Utils.h"
#include "InputUtils.h"
#include "GameModeCorr.h"

APlayerPawnCorrection::APlayerPawnCorrection()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	ATTACH_TO(springArm, RootComponent);
	ATTACH_TO(camera, springArm);
	demoTimer = CreateDefaultSubobject<UTimerComponent>("DemoTimer");
	AddOwnedComponent(demoTimer);
}


void APlayerPawnCorrection::BeginPlay()
{
	Super::BeginPlay();
	InitPawn();
}

void APlayerPawnCorrection::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StartDemo();
}

void APlayerPawnCorrection::InitPawn()
{
	grid = GetGrid();
	if (!grid)
		return;
	grid->SnapToStart(this);
	SelectGridCell();
	if (demoTimer)
	{
		BIND(demoTimer->OnTimerEnd(), this, &APlayerPawnCorrection::DemoMode);
	}
}

void APlayerPawnCorrection::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	BIND_ACTION_PAWN(UP, IE_Pressed, this, &APlayerPawnCorrection::UpMove)
	BIND_ACTION_PAWN(DOWN, IE_Pressed, this, &APlayerPawnCorrection::DownMove)
	BIND_ACTION_PAWN(RIGHT, IE_Pressed, this, &APlayerPawnCorrection::RightMove)
	BIND_ACTION_PAWN(LEFT, IE_Pressed, this, &APlayerPawnCorrection::LeftMove)
	BIND_ACTION_PAWN(SELECT, IE_Pressed, this, &APlayerPawnCorrection::SelectGridCell)
}

void APlayerPawnCorrection::UpMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(1, 0, 0));
}
void APlayerPawnCorrection::DownMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(-1, 0, 0));
}
void APlayerPawnCorrection::LeftMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(0, -1, 0));
}
void APlayerPawnCorrection::RightMove()
{
	if (!grid)
		return;
	grid->MoveToCellDirection(this, FVector(0, 1, 0));
}
void APlayerPawnCorrection::SelectGridCell()
{
	if (!grid)
		return;
	grid->PickLocation(this);
}


TObjectPtr<AGridActor> APlayerPawnCorrection::GetGrid() const
{
	AGameModeCorr * _gm = WORLD->GetAuthGameMode<AGameModeCorr>();
	if (!_gm)
		return nullptr;
	return _gm->GetGrid();
}


void APlayerPawnCorrection::DemoMode()
{
	if (!demo.isDemoMode)
		return;
	if (demo.moveNumber < demo.maxMoveNumber)
	{
		grid->MoveToCellDirection(this, demo.GetDirection());
		demo.moveNumber++;
		demoTimer->ResetTimer();
	}
	else if (demo.moveNumber == demo.maxMoveNumber)
	{
		grid->PickLocation(this);
		demo.moveNumber = 0;
		demo.maxMoveNumber = demo.GetMaxMoveNumber();
		demoTimer->SetMaxTimer(3.0f);
		demoTimer->ResetTimer();
	}
}

void APlayerPawnCorrection::StartDemo()
{
	if (!demo.isDemoMode)
		return;
	demoTimer->SetMaxTimer(0.5f);
	demoTimer->StartTimer();
}
