// Fill out your copyright notice in the Description page of Project Settings.


#include "GridComponent.h"
#include "Utils.h"

UGridComponent::UGridComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UGridComponent::BeginPlay()
{
	Super::BeginPlay();
	settings.startLocation = GetOwner()->GetActorLocation();
}


void UGridComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ShowGrid();
}

void UGridComponent::ShowGrid()
{
    for (int i = 0; i < settings.verticalLine; i++)
    {
        DRAW_LINE(settings.startLocation + FVector(200, 0, 0) * i,
            settings.startLocation + FVector(200, 0, 0) * i + FVector(0, 200, 0) * (settings.horizontalLine - 1),
            FColor::Red, 4);
    }
    for (int i = 0; i < settings.horizontalLine; i++)
    {
        DRAW_LINE(settings.startLocation + FVector(0, 200, 0) * i,
            settings.startLocation + FVector(0, 200, 0) * i + FVector(200, 0, 0) * (settings.verticalLine - 1),
            FColor::Red, 4);
    }
}

void UGridComponent::MoveUp()
{
    if (GetActorLocation().X == settings.startLocation.X + 200 * (settings.verticalLine - 1))
        return;
    SetActorLocation(GetActorLocation() + FVector(200, 0, 0));
}

void UGridComponent::MoveDown()
{
    if (GetActorLocation().X == settings.startLocation.X)
        return;
    SetActorLocation(GetActorLocation() + FVector(-200, 0, 0));

}

void UGridComponent::MoveRight()
{
    if (GetActorLocation().Y == settings.startLocation.Y + 200 * (settings.horizontalLine - 1))
        return;
    SetActorLocation(GetActorLocation() + FVector(0, 200, 0));
}

void UGridComponent::MoveLeft()
{
    if (GetActorLocation().Y == settings.startLocation.Y)
        return;
    SetActorLocation(GetActorLocation() + FVector(0, -200, 0));

}