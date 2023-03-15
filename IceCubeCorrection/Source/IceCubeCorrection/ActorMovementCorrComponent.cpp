

#include "ActorMovementCorrComponent.h"
#include "Utils.h"
#include "Inpututils.h"

UActorMovementCorrComponent::UActorMovementCorrComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
}

void UActorMovementCorrComponent::MoveForward(float _axis)
{
	if (isInResetStatus)
		return;
	settings.forwardAxis = LERP(settings.forwardAxis, _axis, DELTATIME * settings.forwardWeight);
}

void UActorMovementCorrComponent::MoveHorizontal(float _axis)
{
	if (isInResetStatus)
		return;
	settings.horizontalAxis = LERP(settings.horizontalAxis, _axis, DELTATIME * settings.horizontalWeight);

}

void UActorMovementCorrComponent::Rotate(float _axis)
{
	if (isInResetStatus)
		return;
	settings.rotateAxis = LERP(settings.rotateAxis, _axis, DELTATIME * settings.rotateWeight);
}


void UActorMovementCorrComponent::BeginPlay()
{
	Super::BeginPlay();
	settings.initLocation = GetOwner()->GetActorLocation();
}


void UActorMovementCorrComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateMovement();
	UpdateRotation();
	ResetBehaviour();
	DRAW_SPHERE_DEF(GetOwner()->GetActorLocation() + GetVelocity() * 200, 10, 5, FColor::Green, 2)
	DRAW_LINE(GetOwner()->GetActorLocation() + GetVelocity() * 200, GetOwner()->GetActorLocation(), FColor::Green, 2)

	DRAW_BOX(settings.initLocation, FVector(10), FColor::Cyan, 2)
	DRAW_LINE(GetOwner()->GetActorLocation(), settings.initLocation, FColor::Cyan, 2)
}

void UActorMovementCorrComponent::UpdateMovement()
{
	if (isInResetStatus)
		return;
	GetOwner()->AddActorWorldOffset(GetVelocity());
}

void UActorMovementCorrComponent::UpdateRotation()
{
	if (isInResetStatus)
		return;
	GetOwner()->AddActorLocalRotation(GetRotationVelocity());
}

void UActorMovementCorrComponent::ResetBehaviour()
{
	if (!isInResetStatus)
		return;
	if (settings.UpdateTimer(WORLD))
	{
		OnEndReset();
		return;
	}
	onResetMovement.Broadcast(settings.GetResetRatio());
	GetOwner()->SetActorLocation(LERP(settings.currentLocation, settings.initLocation, settings.GetResetRatio()));
}

void UActorMovementCorrComponent::CallReset()
{
	if (isInResetStatus)
		return;
	settings.currentLocation = GetOwner()->GetActorLocation();
	settings.ResetValues();
	isInResetStatus = true;
}

void UActorMovementCorrComponent::OnEndReset()
{
	isInResetStatus = false;
}

