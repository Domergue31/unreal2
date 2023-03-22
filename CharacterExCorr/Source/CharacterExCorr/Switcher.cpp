// Fill out your copyright notice in the Description page of Project Settings.


#include "Switcher.h"
#include "MainCharacter.h"

ASwitcher::ASwitcher()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}
void ASwitcher::BeginPlay()
{
	Super::BeginPlay();
	Init();
}


void ASwitcher::Switch()
{
	if (!fpc || switchTeam.Num() == 0)
		return;
	AMainCharacter* _next = switchTeam[currentSwitchIndex];
	if (!_next)
		return;
	if (currentChar)
		currentChar->SetControl(false);
	fpc->Possess(_next);
	currentChar = _next;
	currentChar->SetControl(true);
}

void ASwitcher::IncrementSwitch()
{
	currentSwitchIndex++;
	currentSwitchIndex = FMath::Fmod(currentSwitchIndex, switchTeam.Num());
	onIncrementSwitch.Broadcast();
}


void ASwitcher::Init()
{
	onIncrementSwitch.AddDynamic(this, &ASwitcher::Switch);
	fpc = GetWorld()->GetFirstPlayerController();
	if (!fpc)
		return;
	fpc->InputComponent->BindAction("Switch", IE_Pressed, this, &ASwitcher::IncrementSwitch);
	fpc->InputComponent->BindAction("Spawn", IE_Pressed, this, &ASwitcher::AddFriend);
	Switch();
}


void ASwitcher::AddFriend()
{
	//copy = GetWorld()->SpawnActor<AMainCharacter>(originalToCopy, GetActorLocation(), FRotator::ZeroRotator);
	//if (!copy)
	//	return;
	//switchTeam.Add(copy);

	if (switchTeam.Num() < maxTeam)
	{
		FVector _finalDestination = currentChar->GetActorLocation() + currentChar->GetActorRightVector() * 100;
		AMainCharacter* _teamMate = GetWorld()->SpawnActor<AMainCharacter>(originalToCopy, _finalDestination, FRotator(0));
		switchTeam.Add(_teamMate);
	}
}