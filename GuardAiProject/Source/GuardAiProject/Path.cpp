// Fill out your copyright notice in the Description page of Project Settings.


#include "Path.h"
#include "GuardGameMode.h"

APath::APath()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
}

void APath::BeginPlay()
{
	Super::BeginPlay();
	AGuardGameMode* _gm = GetWorld()->GetAuthGameMode<AGuardGameMode>();
	if (_gm)
		_gm->GetPathManager()->Register(this);

	points.Remove(nullptr);
	for (size_t i = 0; i < points.Num(); i++)
			points[i]->SetPath(this);
}

void APath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawPath();
}

void APath::DrawPath()
{
	for (size_t i = 0; i < points.Num() - 1; i++)
	{
		if (!points[i] || !points[i + 1]) return;
		DrawDebugLine(GetWorld(), points[i]->GetActorLocation(), points[i + 1]->GetActorLocation(), FColor::Yellow, false, -1, 0, 2);
		DrawDebugSphere(GetWorld(), points[i]->GetActorLocation(), 25, 20, FColor::Magenta, false, -1, 0, 2);
	}
	if(points[points.Num() - 1])
		DrawDebugSphere(GetWorld(), points[points.Num() - 1]->GetActorLocation(), 25, 20, FColor::Magenta, false, -1, 0, 2);
}

bool APath::ShouldTickIfViewportsOnly() const
{
	return false;
}

AWaypoint* APath::GetStartingPoint() const
{
	if (points.Num() == 0)
		return nullptr;
	return points[0];
}
