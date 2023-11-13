

#include "PNJActor.h"
#include <Kismet/KismetMathLibrary.h>

APNJActor::APNJActor()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif

}
void APNJActor::BeginPlay()
{
	Super::BeginPlay();
}
void APNJActor::MoveTarget()
{
	camera->SetActorLocation(camera->FinalPosition(this));
	UE_LOG(LogTemp, Warning, TEXT(" camera ====> x = %f, y = %f, z = %f"), camera->GetActorLocation().X, camera->GetActorLocation().Y, camera->GetActorLocation().Z)
	UE_LOG(LogTemp, Warning, TEXT("actor ====> x = %f, y = %f, z = %f"), GetCenterPosition().X, GetCenterPosition().Y, GetCenterPosition().Z)
	camera->SetActorRotation(UKismetMathLibrary::FindLookAtRotation(camera->GetActorLocation(), GetCenterPosition()));
	target->SetActorLocation(GetTargetFinalPosition());
}
void APNJActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->IsPlayInEditor() && !VerifPosition())
		MoveTarget();
	ShowDebug();
	camera->GetActorLocation() ^ FVector(0);
}

void APNJActor::ShowDebug()
{
	if (!camera || !target || !useDebug)
		return;
	const UWorld* _world = GetWorld();
	DrawDebugBox(_world, camera->GetActorLocation(), FVector(50), FColor::Green, false, -1, 0, 3);
	DrawDebugBox(_world, target->GetActorLocation(), FVector(50), FColor::Yellow, false, -1, 0, 3);

	DrawDebugLine(_world, GetActorLocation(), camera->GetActorLocation(), FColor::Magenta, false, -1, 0, 2);
	DrawDebugLine(_world, GetActorLocation(), target->GetActorLocation(), FColor::Magenta, false, -1, 0, 2);

	DrawDebugLine(_world, camera->FinalPosition(this), camera->GetActorLocation(), FColor::Red, false, -1, 0, 2);
	DrawDebugLine(_world, (GetActorLocation() + GetActorForwardVector() * settings->Distance()), target->GetActorLocation(), FColor::Red, false, -1, 0, 2);

	DrawDebugSphere(_world, (GetActorLocation() + GetActorForwardVector() * (settings->Distance() / 2)), 50, 10, FColor::Cyan, false, -1, 0, 2);

	DrawDebugBox(_world, (GetActorLocation() + GetActorForwardVector() * settings->Distance()), FVector(20), FColor::Red, false, -1, 0, 3);
	DrawDebugBox(_world, camera->FinalPosition(this), FVector(20), FColor::Red, false, -1, 0, 3);
}

bool APNJActor::ShouldTickIfViewportsOnly() const
{
	return useDebug;
}


bool APNJActor::VerifPosition()
{
	return camera->GetActorLocation() == GetCameraFinalPosition() && target->GetActorLocation() == GetTargetFinalPosition();
}
