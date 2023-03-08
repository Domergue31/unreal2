// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlActor.h"
#include "Utils.h"
#include <Kismet/KismetMathLibrary.h>


AControlActor::AControlActor()
{
    PrimaryActorTick.bCanEverTick = true;
    icon = CreateDefaultSubobject<UBillboardComponent>("Root");
    RootComponent = icon;
}


void AControlActor::DrawDebug()
{
    DRAW_BOX(GetActorLocation(), FVector(50), FColor::Red, 2)
        DRAW_SPHERE(GetTargetLocation(), 50, FColor::Cyan, 2)
        DRAW_LINE(GetActorLocation(), GetTargetLocation(), FColor::Magenta, 2)
        const FLinearColor _progressColor = UKismetMathLibrary::LinearColorLerp(FLinearColor::Red, FLinearColor::Green, GetTimerProgressNormalized());
    DRAW_BOX(GetActorLocation() + FVector(0, 0, 100), (FVector(25) * GetTimerProgressNormalized()) + FVector(10), _progressColor.ToFColor(true), 2);
    DRAW_TEXT(GetActorLocation(), FString::Printf(TEXT("timer %f -> progress %d p"), timer, (int)GetTimerProgressPercent()), FColor::Red, 1.2f);
}

void AControlActor::TakeControl()
{
    if (!target)
        return;
    target->SetCanMove(true);
}

bool AControlActor::UpdateTimer(float& _timer, const float& _max)
{
    if (!isStarted)
        return false;
    _timer += DELTATIME;
    if (_timer > _max)
    {
        _timer = 0;
        if (!isLoopTimer)
        {
            isStarted = false;
            return true;
        }
        onTimerReached.Broadcast();
        return true;
    }
    return false;
}

UFUNCTION() void AControlActor::TestAction()
{
    LOG_W(LogTemp, "Toto")
}

UFUNCTION() void AControlActor::TestActionParam(bool _value)
{
    if (_value)
    {
        LOG_E(LogTemp, "true")
    }
    else LOG_E(LogTemp, "false")
}
void AControlActor::BeginPlay()
{
    Super::BeginPlay();
    onTimerReached.AddDynamic(this, &AControlActor::TakeControl);
    onTimerReached.AddDynamic(this, &AControlActor::TestAction);
    onParam.AddDynamic(this, &AControlActor::TestActionParam);
    onParam.Broadcast(true);
    onParam.RemoveDynamic(this, &AControlActor::TestActionParam);
    //TakeControl();
}

void AControlActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    DrawDebug();
    UpdateTimer(timer, maxTime);
    //TakeControl();
}