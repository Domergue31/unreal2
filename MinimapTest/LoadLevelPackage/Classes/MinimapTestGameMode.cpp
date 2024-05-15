// Copyright Epic Games, Inc. All Rights Reserved.

#include "MinimapTestGameMode.h"
#include "MinimapTestCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AMinimapTestGameMode::AMinimapTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMinimapTestGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	if (streamingManagerRef)
	{
		streamingManager = GetWorld()->SpawnActor<AStreamingSourceManager>(streamingManagerRef);
		UKismetSystemLibrary::PrintString(this, "GameMode Init", true, true, FLinearColor::Black, 5);
	}
}


void AMinimapTestGameMode::LoadLevel(const FName& _nameLevel)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, _nameLevel, true, false, LatentInfo);
}

void AMinimapTestGameMode::UnloadLevel(const FName& _nameLevel)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::UnloadStreamLevel(this, _nameLevel, LatentInfo, true);
}


