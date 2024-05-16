// Fill out your copyright notice in the Description page of Project Settings.


#include "CWP_StreamManagerSubsystem.h"
#include "CWP_GameMode.h"
#include "CWP_Octree.h"
#include "Kismet/KismetSystemLibrary.h"

UCWP_StreamManagerSubsystem::UCWP_StreamManagerSubsystem()
{

}

void UCWP_StreamManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	//GetWorld()->GetTimerManager().SetTimer(updateTimer, this, &UCWP_StreamManagerSubsystem::Update, 0.01f, true, 0.1f);
}

void UCWP_StreamManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	//GetWorld()->GetTimerManager().ClearTimer(updateTimer);
}

void UCWP_StreamManagerSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Update();
}

void UCWP_StreamManagerSubsystem::Update()
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
