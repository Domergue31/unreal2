// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MarioTimerManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MARIOCORR_API UMarioTimerManager : public UObject
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerProgress, int, _timer);
	FOnTimerProgress onTimerProgress;

	UPROPERTY(EditAnywhere)
		int maxTime = 300;

	int tickProgress;
	FTimerHandle timer;
private:
	void TickProgress();
public:
	FORCEINLINE FOnTimerProgress& OnTimerProgress() { return onTimerProgress; }
	FORCEINLINE int GetTickProgress() const { return tickProgress; }
	void StartTimer(UWorld* _world);
	void StopTimer(UWorld* _world);
	void RestartTimer(UWorld* _world);
};
