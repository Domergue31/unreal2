#include "CWP_GameMode.h"
#include "CWP_Octree.h"
#include "CWP_StreamManager.h"
#include "Kismet/GameplayStatics.h"

void ACWP_GameMode::LoadLevel(const FName& _nameLevel)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::LoadStreamLevel(this, _nameLevel, true, false, LatentInfo);
}

void ACWP_GameMode::UnloadLevel(const FName& _nameLevel)
{
	FLatentActionInfo LatentInfo;
	UGameplayStatics::UnloadStreamLevel(this, _nameLevel, LatentInfo, true);
}