// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillsLauncherComponent.h"

USkillsLauncherComponent::USkillsLauncherComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void USkillsLauncherComponent::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->GetWorldTimerManager().SetTimer(spawnTimerTest, this, &USkillsLauncherComponent::InvokeSkill, 5, true);
	InvokeSkill();
}



void USkillsLauncherComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USkillsLauncherComponent::InvokeSkill()
{
	const int _index = FMath::RandRange(0, skills.Num() - 1);
	if (_index < 0)
		return;
	USkills* _skill = skills[_index];
	if (!_skill)
		return;
	_skill->Spawn(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation().Yaw);
}

