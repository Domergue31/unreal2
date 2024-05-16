#include "CWP_StreamManager.h"
#include "CWP_GameMode.h"
#include "CWP_Octree.h"

ACWP_StreamManager::ACWP_StreamManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACWP_StreamManager::BeginPlay()
{
	Super::BeginPlay();

	if (ACWP_GameMode* _gameMode = GetWorld()->GetAuthGameMode<ACWP_GameMode>())
	{
		octree = _gameMode->GetOctree();

		if (!octree)
		{
			_gameMode->OnOctreeSet()->AddDynamic(this, &ACWP_StreamManager::SetOctree);
		}
	}
}

void ACWP_StreamManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TODO move
	//Update();
}

void ACWP_StreamManager::Update()
{
	if (!octree) return;

	/* Reset visibility of the children */
	TArray<ACWP_Octree*> _allChildren = octree->GetOctreesWithoutChildren();
	const int _childrenCount = _allChildren.Num();

	for (int _index = 0; _index < _childrenCount; _index++)
	{
		ACWP_Octree* _octree = _allChildren[_index];
		_octree->ChangeVisibility(false);
	}


	/* Check all children */
	TArray<ACWP_Octree*> _allStreamedOctrees;
	const int _allSourcesCount = allSourcesComponent.Num();

	for (int _index = 0; _index < _allSourcesCount; _index++)
	{
		TArray<ACWP_Octree*> _streamedOctrees = allSourcesComponent[_index]->UpdateStreaming(octree);
		const int _streamCount = _streamedOctrees.Num();

		for (int _streamIndex = 0; _streamIndex < _streamCount; _streamIndex++)
		{
			ACWP_Octree* _octree = _streamedOctrees[_streamIndex];
			if (_allStreamedOctrees.Contains(_octree)) continue;
			_allStreamedOctrees.Add(_octree);
		}
	}

	/* Active valid children */
	const int _allStreamedCount = _allStreamedOctrees.Num();
	for (int _allStreamedIndex = 0; _allStreamedIndex < _allStreamedCount; _allStreamedIndex++)
	{
		_allStreamedOctrees[_allStreamedIndex]->ChangeVisibility(true);
	}
}