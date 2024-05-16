#include "CWP_PlayerController.h"
#include "EnhancedInputSubsystems.h"

void ACWP_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* _subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		_subsystem->AddMappingContext(mappingContext, 0);
	}
}