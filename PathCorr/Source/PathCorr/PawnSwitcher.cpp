// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnSwitcher.h"

APawnSwitcher::APawnSwitcher()
{
	PrimaryActorTick.bCanEverTick = true;
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
}
void APawnSwitcher::BeginPlay()
{
	Super::BeginPlay();
	onSelect.AddDynamic(this, &APawnSwitcher::SwitchView);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Previous", IE_Pressed, this, &APawnSwitcher::SelectPrevious);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Next", IE_Pressed, this, &APawnSwitcher::SelectNext);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Switch", IE_Pressed, this, &APawnSwitcher::Switch);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction("Release", IE_Pressed, this, &APawnSwitcher::Release);
}
void APawnSwitcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}
void APawnSwitcher::AddPawn(ACharacterPath* _pawn)
{
	movablePawn.Add(_pawn);
}
void APawnSwitcher::RemovePawn(ACharacterPath* _pawn)
{
	movablePawn.Remove(_pawn);
}
void APawnSwitcher::SwitchView()
{
	if (selectIndex >= 0 && selectIndex <= movablePawn.Num() - 1)
	{
		if (current)
			Release();
		current = movablePawn[selectIndex];
		if (!current)
			return;
		GetWorld()->GetFirstPlayerController()->SetViewTarget(current);
	}
}
void APawnSwitcher::Switch()
{
	if (current)
	{
		current->ControlCharacter();
		GetWorld()->GetFirstPlayerController()->Possess(current);
	}
}
void APawnSwitcher::Release()
{
	if (current)
	{
		if (current->IsControlled())
			GetWorld()->GetFirstPlayerController()->UnPossess();
		current->FreeCharacter();
	}

}
void APawnSwitcher::SelectNext()
{
	if (movablePawn.Num() == 0)
		return;
	selectIndex++;
	selectIndex = FMath::Fmod(selectIndex, movablePawn.Num() - 1);
	onSelect.Broadcast();
}
void APawnSwitcher::SelectPrevious()
{
	if (movablePawn.Num() == 0)
		return;
	selectIndex--;
	selectIndex = selectIndex < 0 ? (movablePawn.Num() - 1) : selectIndex;
	onSelect.Broadcast();
}
void APawnSwitcher::DrawDebug()
{
	for (ACharacterPath* _pawn : movablePawn)
	{
		if (!_pawn)
			return;
		DrawDebugLine(GetWorld(), _pawn->GetActorLocation(), GetActorLocation(), FColor::Cyan, false, -1, 0, 2);
	}
}

