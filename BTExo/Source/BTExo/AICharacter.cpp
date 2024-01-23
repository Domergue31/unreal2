// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "CustomAIController.h"

AAICharacter::AAICharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	aiController = Cast<ACustomAIController>(UAIBlueprintHelperLibrary::GetAIController(this));
}
