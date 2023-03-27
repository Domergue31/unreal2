// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "CharacterPath.h"
#include "PawnSwitcher.generated.h"

UCLASS()
class PATHCORR_API APawnSwitcher : public AActor
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelect);

	FOnSelect onSelect;
		UPROPERTY(VisibleAnywhere)
		TArray<ACharacterPath*> movablePawn;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UBillboardComponent> icon = nullptr;
	UPROPERTY()
		TObjectPtr<ACharacterPath> current = nullptr;

	int selectIndex = 0;
public:	
	APawnSwitcher();
	void AddPawn(ACharacterPath* _pawn);
	void RemovePawn(ACharacterPath* _pawn);
protected:
	UFUNCTION() void SwitchView();
	void Switch();
	void Release();
	void SelectNext();
	void SelectPrevious();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void DrawDebug();
};
