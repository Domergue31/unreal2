// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCharacter.h"
#include "Switcher.generated.h"

UCLASS()
class CHARACTEREXCORR_API ASwitcher : public AActor
{
	GENERATED_BODY()

		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIncrementSwitch);

	UPROPERTY(EditAnywhere)
		TArray<AMainCharacter*> switchTeam;
	UPROPERTY()
		TObjectPtr<AMainCharacter> currentChar = nullptr;
	UPROPERTY()
		TObjectPtr<AController> fpc = nullptr;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AMainCharacter> originalToCopy = nullptr;
	UPROPERTY(EditAnywhere, meta = (UIMin = 1, UIMax = 10, ClampMin = 1, ClampMax = 10))
		int maxTeam = 5;


	int currentSwitchIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintCallable, BlueprintAssignable, meta = (AllowPrivateAccess))
		FOnIncrementSwitch onIncrementSwitch;

public:	
	ASwitcher();

protected:
	UFUNCTION() void Switch();
	void IncrementSwitch();
	virtual void BeginPlay() override;
	void AddFriend();
	void Init();

};
