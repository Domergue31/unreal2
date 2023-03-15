// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXERCICEPROJECT_API UTimerComponent : public UActorComponent
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerChange);
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimerEnd);

	FOnTimerChange onTimerChange;
	FOnTimerEnd onTimerEnd;


	UPROPERTY(EditAnywhere)
		float timerMax = 30.0f;
	UPROPERTY(VisibleAnywhere)
		float timer;

	UPROPERTY(VisibleAnywhere)
		bool isStarted = false;

public:	
	UTimerComponent();
	FORCEINLINE FOnTimerChange& OnTimerChange()  { return onTimerChange; }
	FORCEINLINE FOnTimerEnd& OnTimerEnd()  { return onTimerEnd; }
	FORCEINLINE void StartTimer() { isStarted = true; }
	FORCEINLINE void StopTimer() { isStarted = false; }
	FORCEINLINE float TimerProgressNormalized() { return timer / timerMax; }
	UFUNCTION() void ResetTimer();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void UpdateTimer(float& _timer, const float& _max);
		
};
