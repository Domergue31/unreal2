// Fill out your copyright notice in the Description page of Project Settings.


#include "InputConfig.h"
#include <EnhancedInputSubsystems.h>


void UInputConfig::EnableInputContext(ULocalPlayer* _player)
{
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(_player);
	_inputSystem->ClearAllMappings();
	_inputSystem->AddMappingContext(context.LoadSynchronous(), 0);
}