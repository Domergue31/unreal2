

#include "CameraActorMovement.h"

ACameraActorMovement::ACameraActorMovement()
{
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = camera;
}

void ACameraActorMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACameraActorMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateCameraPosition();
}

void ACameraActorMovement::UpdateCameraPosition() {}

void ACameraActorMovement::DrawDebug() {}

FVector ACameraActorMovement::GetLocalOffset(const float& _x, const float& _y, const float& _z)
{
	return (target->GetActorForwardVector() * _x +
			target->GetActorRightVector() * _y +
			target->GetActorUpVector() * _z);
}

