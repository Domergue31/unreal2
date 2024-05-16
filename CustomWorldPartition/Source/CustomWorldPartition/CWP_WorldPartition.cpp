#include "CWP_WorldPartition.h"

ACWP_WorldPartition::ACWP_WorldPartition()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}


void ACWP_WorldPartition::Generate()
{
	Clear();

	const int _columnsCount = grid.size.X / grid.cellSize;
	const int _rowsCount = grid.size.Y / grid.cellSize;
	const float _currentZ = GetActorLocation().Z;

	if (!octreeType.Get())
	{
		UE_LOG(LogTemp, Warning, TEXT("You forgot to setup an octree type to spawn !"));
		return;
	}

	for (int _columnIndex = -_columnsCount; _columnIndex < _columnsCount; _columnIndex++)
	{
		for (int _rowIndex = -_rowsCount; _rowIndex < _rowsCount; _rowIndex++)
		{
			const float _posX = _columnIndex * grid.cellSize / 2.0f;
			const float _posY = _rowIndex * grid.cellSize / 2.0f;
			const FVector& _position = GetActorLocation() + FVector(_posX, _posY, _currentZ);

			ACWP_Octree* _octree = GetWorld()->SpawnActor<ACWP_Octree>(octreeType);
			_octree->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			_octree->Place(_position, grid.cellSize);
			_octree->Update();
			allOctrees.Add(_octree);
		}
	}
}

void ACWP_WorldPartition::SwitchVisibility()
{
	const int _octreeCount = allOctrees.Num();
	for (int _index = 0; _index < _octreeCount; _index++)
	{
		allOctrees[_index]->SwitchVisibility();
	}
}

void ACWP_WorldPartition::Clear()
{
	const int _octreesCount = allOctrees.Num();
	for (int _index = 0; _index < _octreesCount; _index++)
	{
		allOctrees[_index]->Clear();
		allOctrees[_index]->Destroy();
	}

	allOctrees.Empty();
}