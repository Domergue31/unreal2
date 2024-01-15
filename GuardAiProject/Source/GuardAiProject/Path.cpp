// Fill out your copyright notice in the Description page of Project Settings.


#include "Path.h"

APath::APath()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
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
		if (!points[i] || !points[i + 1])
		{
			UE_LOG(LogTemp, Warning, TEXT("null"));
			return;
		}
		DrawDebugLine(GetWorld(), points[i]->GetActorLocation(), points[i + 1]->GetActorLocation(), FColor::Yellow, false, -1, 0, 2);
		DrawDebugSphere(GetWorld(), points[i]->GetActorLocation(), 25, 20, FColor::Magenta, false, -1, 0, 2);
	}
	//DrawDebugSphere(GetWorld(), points[points.Num() - 1]->GetActorLocation(), 25, 20, FColor::Magenta, false, -1, 0, 2);
}

bool APath::ShouldTickIfViewportsOnly() const
{
	return false;
}
