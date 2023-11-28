
#include "NavigationComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

UNavigationComponent::UNavigationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UNavigationComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UNavigationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!canMove)
		return;
	Move();
	DrawDebug();
}

bool UNavigationComponent::LocationClicked()
{
	FVector _worldLocation, _worldDirection;
	GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(_worldLocation, _worldDirection);
	FHitResult _result;

	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, _worldLocation, _worldLocation + _worldDirection * 10000, clickedMask, false,
		TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);

	targetLocation = CanGo(_result.ImpactPoint) ? _result.ImpactPoint : targetLocation;
	return targetLocation == _result.ImpactPoint;
}

bool UNavigationComponent::CanGo(FVector _targetPosition)
{
	FHitResult _result;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, GetOwnerLocation(), _targetPosition, moveMask, false,
		TArray<AActor*>(), EDrawDebugTrace::ForOneFrame, _result, false);
	return !_hit;
}

void UNavigationComponent::Move()
{
	SetOwnerLocation(FMath::VInterpConstantTo(GetOwnerLocation(), targetLocation, GetWorld()->DeltaTimeSeconds, speed));

	if (!IsAtDestination(GetOwnerLocation(), targetLocation))
		return;
	canMove = false;
	onMove.Broadcast(0);
}

void UNavigationComponent::SetRotation()
{
	FRotator _lookAt = UKismetMathLibrary::FindLookAtRotation(GetOwnerLocation(), targetLocation);
	FRotator _rotation = FRotator(0, _lookAt.Yaw, 0);
	GetOwner()->SetActorRotation(FRotator(_rotation));
}

void UNavigationComponent::DrawDebug()
{
		DrawDebugLine(GetWorld(), GetOwnerLocation(), targetLocation, FColor::Magenta, false, -1, 0, 2);
		DrawDebugSphere(GetWorld(), targetLocation, 20, 2, FColor::Green, false, -1, 0, 2);
}

void UNavigationComponent::Clicked()
{
	canMove = LocationClicked();
	if (!canMove)
		return;
	targetLocation.Z = GetOwnerLocation().Z;
	SetRotation();
	onMove.Broadcast(1);
}


bool UNavigationComponent::IsAtDestination(FVector _a, FVector _b)
{
	return _a.Equals(_b, 0);
}

