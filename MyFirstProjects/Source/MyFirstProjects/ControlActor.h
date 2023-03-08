// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstActor.h"
#include "Utils.h"
#include "Components/BillboardComponent.h"
#include "ControlActor.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API AControlActor : public AActor
{
	GENERATED_BODY()
	
        DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerReached);
        DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionParam, bool, _param);

    UPROPERTY(EditAnywhere)
        TObjectPtr<UBillboardComponent> icon = nullptr;

    UPROPERTY(EditAnywhere, Category = Control)
        bool useTimer = true;
    UPROPERTY(EditAnywhere, Category = Timer, meta = (EditCondition = "useTimer"))
        bool isLoopTimer = false;
    UPROPERTY(EditAnywhere, Category = Timer, meta = (EditCondition = "useTimer"))
        bool isStarted = true;

    UPROPERTY(EditAnywhere, Category = Control)
        TObjectPtr<AMyfirstActor> target = nullptr;

    UPROPERTY(EditAnywhere, Category = Control, meta = (EditCondition = "useTimer", UMin = 0, ClampMin = 0))
        float maxTime = 5;
    FOnTimerReached onTimerReached;
    FActionParam onParam;

    float timer = 0;
public:	
	// Sets default values for this actor's properties
	AControlActor();
    FORCEINLINE float GetTimerProgressPercent() const { return (timer / maxTime) * 100.0f; }
    FORCEINLINE float GetTimerProgressNormalized() const { return (timer / maxTime); }
    FORCEINLINE FVector GetTargetLocation() const { return target ? target->GetActorLocation() : GetActorLocation(); }
    FORCEINLINE FOnTimerReached& OnTimerReached() { return onTimerReached; }
private:
    void DrawDebug();
    UFUNCTION() void TakeControl();
    bool UpdateTimer(float& _timer, const float& _max);
    UFUNCTION() void TestAction();
    UFUNCTION() void TestActionParam(bool _value);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
