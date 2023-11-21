// Fill out your copyright notice in the Description page of Project Settings.


#include "RicochetArrowActor.h"
#include "ProjectsUtils.h"

void ARicochetArrowActor::BeginPlay()
{
    Super::BeginPlay();
}

void ARicochetArrowActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ARicochetArrowActor::Move()
{
    if (path.Num() == 0)
        Destroy();

    FVector _newPos = FMath::VInterpConstantTo(GetActorLocation(), path[currentIndex], DELTATIME, speed);
    SetActorLocation(_newPos);

    if (GetActorLocation().Equals(path[currentIndex]))
        ChangeCurrentIndex();
}

void ARicochetArrowActor::ChangeCurrentIndex()
{
    currentIndex++;
    if (currentIndex == path.Num())
        Destroy();
}
