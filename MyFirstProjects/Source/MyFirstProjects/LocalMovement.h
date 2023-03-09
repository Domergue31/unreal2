// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "LocalMovement.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API ALocalMovement : public AActor
{
    GENERATED_BODY()

        DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerMove);
        DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerReached, float&, _param);

    


        UPROPERTY(EditAnywhere, Category = Debug)
        bool isDebuging = false;

        UPROPERTY(EditAnywhere, Category = Movement, meta = (EditCondition = "!isRightAxe && !isUpAxe"))
            bool isForwardAxe = true;
    UPROPERTY(EditAnywhere, Category = Movement, meta = (EditCondition = "!isForwardAxe && !isUpAxe"))
        bool isRightAxe = false;
    UPROPERTY(EditAnywhere, Category = Movement, meta = (EditCondition = "!isForwardAxe && !isRightAxe"))
        bool isUpAxe = false;

    UPROPERTY(EditAnywhere, Category = Movement)
        bool isStarted = true;

    UPROPERTY(EditAnywhere, Category = Movement)
        float MaxTime = 10.0f;

    float timer = 0.0f;

    UPROPERTY(EditAnywhere, Category = Movement, meta = (UIMin = 0, ClampMin = 0))
        float speed = 1;
    UPROPERTY(EditAnywhere, Category = Rotation, meta = (UIMin = 0, ClampMin = 0))
        float rotationSpeed = 1;
    UPROPERTY(EditAnywhere, Category = Scale, meta = (UIMin = 0, ClampMin = 0))
        float scaleSpeed = 1;


    float rotation = 0;
    float MaxRotation = 360;

    UPROPERTY(EditAnywhere, Category = Scale)
        float scale = GetActorScale().X;
    UPROPERTY(EditAnywhere, Category = Scale, meta = (UIMin = 0, ClampMin = 0))
    float maxScale = scale * 2;
    UPROPERTY(EditAnywhere, Category = Scale, meta = (UIMin = 0, ClampMin = 0))
        float minScale = 1;

    UPROPERTY(VisibleAnywhere, Category = Scale)
    bool isGrowing = true;

    FOnTimerReached onTimerReached;
    FOnTimerMove onTimerMove;

       UPROPERTY(EditAnyWhere)
        TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:

    ALocalMovement();
    FORCEINLINE float GetTimerProgressNormalize() const { return timer / MaxTime; }
    FORCEINLINE float GetTimerProgressPercent() const { return (timer / MaxTime) * 100; }
    void InitObject();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    void DebugAxis();
    UFUNCTION() void ShowTimerBox();
    void UpdateTimer(float& _timer, const float& _maxTime);
    UFUNCTION() void MoveToAxe();
    UFUNCTION() void Rotate();
    UFUNCTION() void Breath();
    UFUNCTION() void EndTimer(float& _timer);
};
