// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocalMovement.generated.h"

UCLASS()
class MYFIRSTPROJECTS_API ALocalMovement : public AActor
{
    GENERATED_BODY()

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

       UPROPERTY(EditAnyWhere)
        TObjectPtr<UStaticMeshComponent> mesh = nullptr;
public:

    ALocalMovement();

    void InitObject();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    void DebugAxis();
    void UpdateTimer(float& _timer, const float& _maxTime);
    void MoveToAxe();
};
