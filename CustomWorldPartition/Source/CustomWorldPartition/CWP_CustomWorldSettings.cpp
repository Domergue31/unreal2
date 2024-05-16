#include "CWP_CustomWorldSettings.h"
#include "CWP_GameMode.h"
#include "Kismet/KismetSystemLibrary.h"

void ACWP_CustomWorldSettings::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		//FName _levelName = FName(setupSubLevel.Get()->GetName());
		ACWP_GameMode* _gamemode = GetWorld()->GetAuthGameMode<ACWP_GameMode>();
		if (!_gamemode) return;
		_gamemode->LoadLevel(subLevelName);
	}
}
