// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Skills.h"
#include "SkillsLauncherComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPELLCORR_API USkillsLauncherComponent : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<USkills>> skills;
	FTimerHandle spawnTimerTest;
public:
	USkillsLauncherComponent();

private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void InvokeSkill();

};