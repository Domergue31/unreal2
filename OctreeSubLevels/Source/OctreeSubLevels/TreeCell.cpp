// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeCell.h"
#include "Kismet/KismetSystemLibrary.h"

ATreeCell::ATreeCell()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATreeCell::UpdateTree()
{
	//Clear l'Octree ainsi que supr ses enfant

	int parentActorsNumbers = allActorsComponents.Num();

	allActorsComponents = GetActorsComponentInBox();

	const bool _amountReduce = isMaster ? true : parentActorsNumbers <= allActorsComponents.Num() ? true : false;

	if (allActorsComponents.Num() > splitMinQty && _amountReduce)
	{
		if (!spawnAsset)
		{
			UKismetSystemLibrary::PrintString(this, "Failed to Create Children - The is no [SpawnAsset]", true, true, FColor::Red);
			return;

		}
		spawnAsset->Spawn(this);
	}
	else if (master)
	{
		master->AddTreeLeaves(this);
		SpawnSubLevel();
	}

}

void ATreeCell::SetupTree(ATreeCell* _master, const int _splitMinQty, const int _subStep, const FBox& _box, TArray<UTreeComponent*> _comps)
{
	master = _master;
	splitMinQty = _splitMinQty;
	subStep = _subStep;
	cellBox = _box;
	allActorsComponents = _comps;
}

void ATreeCell::SwitchSubLevelState(const bool _state)
{

}

void ATreeCell::AddActorToLevel(AActor* _actor)
{

}

void ATreeCell::RemoveActorOfLevel(AActor* _actor)
{

}

void ATreeCell::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);

	DrawOctreeBox();
}

void ATreeCell::OnConstruction(const FTransform& _transform)
{
	Super::OnConstruction(_transform);

	const FVector& _scale = boxScale / 2.0f;
	const FVector& _min = GetActorLocation() - _scale;
	const FVector& _max = GetActorLocation() + _scale;
	cellBox = FBox(_min, _max);
}

void ATreeCell::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool ATreeCell::ShouldTickIfViewportsOnly() const
{
	return debugSettings.useDebug;
}

void ATreeCell::DrawOctreeBox() const
{
	DrawDebugBox(GetWorld(), cellBox.GetCenter(), cellBox.GetExtent(), debugSettings.debugColor, false, -1, 0, debugSettings.thickness);
}

TArray<UTreeComponent*> ATreeCell::GetActorsComponentInBox()
{
	TArray<UTreeComponent*> _allActorsComponents;
	if (isMaster)
	{
		TArray<AActor*> _actors;
		TArray<UTreeComponent*> _components;
		UKismetSystemLibrary::BoxOverlapActors(this, cellBox.GetCenter(), cellBox.GetExtent(), octreeMask, AActor::StaticClass(), {}, _actors);
		for (AActor* _actor : _actors)
		{
			_actor->GetComponents(UTreeComponent::StaticClass(), _components, true);
			if (_components.Num() == 1)
				_allActorsComponents.Add(_components[0]);
		}
	}
	else
	{
		TArray<UTreeComponent*> _components = allActorsComponents;
		for (UTreeComponent* _comp : _components)
		{
			if (!_comp) continue;

			FBox _actorBox = _comp->GetOwner()->GetStreamingBounds();
			if (cellBox.IsInside(_actorBox))
				_allActorsComponents.Add(_comp);
		}
	}
	return _allActorsComponents;
}

void ATreeCell::SpawnChildren()
{

}

bool ATreeCell::SpawnSubLevel()
{
	return false;
}
