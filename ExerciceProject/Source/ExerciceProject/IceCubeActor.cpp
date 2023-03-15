// Fill out your copyright notice in the Description page of Project Settings.


#include "IceCubeActor.h"
#include "Utils.h"
#include "InputUtils.h"

AIceCubeActor::AIceCubeActor()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
	mesh->SetStaticMesh(LoadObject<UStaticMesh>(this, TEXT("'/Engine/BasicShapes/Cube.Cube'")));
	mesh->SetMaterial(0, LoadObject<UMaterial>(this, TEXT("'/Engine/VREditor/Devices/Vive/M_ViveControllerTrim.M_ViveControllerTrim'")));

	springArm = CreateDefaultSubobject<USpringArmComponent>("CameraAnchor");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);

	customTimer = CreateDefaultSubobject<UTimerComponent>("Timer");
	AddOwnedComponent(customTimer);
}

void AIceCubeActor::BeginPlay()
{
	Super::BeginPlay();
	SetIceCube();
	
}

void AIceCubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (showDebug)
		ShowDebug();
	SetRespawn();
	ResetIceCube();
}

#pragma region Method_Init
void AIceCubeActor::SetIceCube()
{
	InitInput();
	if (isCameraOn)
		WORLD->GetFirstPlayerController()->SetViewTarget(this);
	initLocation = GetActorLocation();
	initScale = GetActorScale();
	initRotation = GetActorRotation();
	if (customTimer)
	{
		BIND(customTimer->OnTimerChange(), this, &AIceCubeActor::Melt);
		BIND(onRespawnEnd, customTimer, &UTimerComponent::ResetTimer);
		BIND(customTimer->OnTimerEnd(), this, &AIceCubeActor::TimerFinish);
		customTimer->StartTimer();
	}
	BIND(onRespawnEnd, this, &AIceCubeActor::SetCanMeltDisable)
}

void AIceCubeActor::InitInput()
{
	BIND_AXIS(HORIZONTAL, this, &AIceCubeActor::MoveRight);
	BIND_AXIS(VERTICAL, this, &AIceCubeActor::MoveForward);
	BIND_AXIS(ROTATIONYAW, this, &AIceCubeActor::RotateYaw);
	BIND_ACTION(RESPAWN, EInputEvent::IE_Pressed, this, &AIceCubeActor::Respawn);
}
#pragma endregion Method_Init

#pragma region Method_Movement_Input
void AIceCubeActor::MoveForward(float _axis)
{
	if (respawn || !canMove)
		return;
	if (_axis != 0.0f)
		SetCanMeltEnable();
	FVector _result = GetActorForwardVector().GetSafeNormal();
	SetActorRelativeLocation(GetActorLocation() + _result * _axis * DELTATIME * speed);
}

void AIceCubeActor::MoveRight(float _axis)
{
	if (respawn || !canMove)
		return;
	if (_axis != 0.0f)
		SetCanMeltEnable();
	FVector _result = GetActorRightVector().GetSafeNormal();
	SetActorRelativeLocation(GetActorLocation() + _result * _axis *  DELTATIME * speed);
}

void AIceCubeActor::RotateYaw(float _axis)
{
	if (respawn || !canMove)
		return;
	if (_axis != 0.0f)
		SetCanMeltEnable();
	SetActorRelativeRotation(GetActorRotation() + FRotator(0, ( -1 *_axis) * DELTATIME * rotationSpeed, 0));
}

void AIceCubeActor::TimerFinish()
{
	canMove = false;
}
#pragma endregion Method_Movement_Input

#pragma region Method_Melt
void AIceCubeActor::Melt()
{
	if (!canMelt)
		return;
	const float _floatScale = initScale.X * (1 - customTimer->TimerProgressNormalized());
	FVector _newScale = FVector(_floatScale);
	FVector _actualLocation = GetActorLocation();
	SetActorLocation(FVector(_actualLocation.X, _actualLocation.Y, initLocation.Z * _floatScale));
	SetActorScale3D(_newScale);
}

void AIceCubeActor::SetCanMeltEnable()
{
	canMelt = true;
	customTimer->StartTimer();
}


void AIceCubeActor::SetCanMeltDisable()
{
	canMelt = false;
	customTimer->StopTimer();
}
#pragma endregion Method_Melt

#pragma region Method_Respawn
void AIceCubeActor::Respawn()
{
	respawn = true;
	customTimer->StopTimer();
}
void AIceCubeActor::ResetIceCube()
{
	if (!respawn)
		return;
	SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(), initLocation, DELTATIME, respawnSpeed));
	SetActorRotation(LERP(GetActorRotation(), initRotation, DELTATIME));
	SetActorScale3D(FMath::VInterpConstantTo(GetActorScale(), initScale, DELTATIME, respawnSpeed / 800));
}
void AIceCubeActor::SetRespawn()
{
	if (GetActorLocation() == initLocation && GetActorScale() == initScale)
	{
		SetActorRotation(initRotation);
		respawn = false;
		canMove = true;
		onRespawnEnd.Broadcast();
	}

}
#pragma endregion Method_Respawn


void AIceCubeActor::ShowDebug()
{
	DRAW_BOX(initLocation, FVector(20), FColor::Red, 2);
	//DRAW_SPHERE(initLocation, 10, FColor::Red, 0.5)
	DRAW_LINE(initLocation, GetActorLocation(), FColor::Orange, 2);
}
