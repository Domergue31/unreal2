// Fill out your copyright notice in the Description page of Project Settings.


#include "OctreeCell.h"
#include "Octree.h"
#include "Kismet/KismetSystemLibrary.h"

AOctreeCell::AOctreeCell()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	box = CreateDefaultSubobject<UBoxComponent>("Box");
	box->SetupAttachment(RootComponent);
}

void AOctreeCell::SetOctree(AOctree* _octree)
{
	octree = _octree;
}

void AOctreeCell::SetCellDimensions(const double _length, const double _width, const double _height)
{
	box->SetBoxExtent(FVector(_length, _width, _height));
}

void AOctreeCell::SetCellDimensions(const FVector& _dimensions)
{
	box->SetBoxExtent(_dimensions);
}

void AOctreeCell::CustomDestroy()
{
	for (size_t i = 0; i < currentNumberOfChildren; i++)
	{
		AOctreeCell* _cell = cellChildren[i];
		if (!_cell) continue;
		_cell->CustomDestroy();
	}
	cellChildren.Empty();
	Destroy();
}

void AOctreeCell::BeginPlay()
{
	Super::BeginPlay();
	onNumberOfActorInsideUpdate.AddDynamic(this, &AOctreeCell::ManageCellBehaviour);
}

void AOctreeCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebug();
}

bool AOctreeCell::ShouldTickIfViewportsOnly() const
{
	return true;
}

void AOctreeCell::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	const int _size = classToDetect.Num();
	for (size_t i = 0; i < _size; i++)
	{
		if (classToDetect[i].GetDefaultObject()->StaticClass() == OtherActor->StaticClass())
		{
			currentActorsInside++;
			actorsInside.Add(OtherActor);
		}
	}
	onNumberOfActorInsideUpdate.Broadcast(currentActorsInside);
}

void AOctreeCell::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	const int _size = classToDetect.Num();
	for (int i = 0; i < _size; i++)
	{
		if (classToDetect[i].GetDefaultObject()->StaticClass() == OtherActor->StaticClass())
		{
			currentActorsInside--;
			actorsInside.Remove(OtherActor);
		}
	}
	onNumberOfActorInsideUpdate.Broadcast(currentActorsInside);
}

void AOctreeCell::InitSubCell(const int _branchingID, AOctree* _octree, AOctreeCell* _parent)
{
	branchingID = _branchingID+1;
	octree = _octree;
	parent = _parent;
}

void AOctreeCell::SubDivideCells(const FVector _subLocation)
{
	if (!octree) return;
	AOctreeCell* _subCell = GetWorld()->SpawnActor<AOctreeCell>(octree->GetOctreeCellToSpawn(), GetActorLocation(), FRotator::ZeroRotator);
	if (!_subCell) return;
	_subCell->InitSubCell(branchingID, octree, this);
	_subCell->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	_subCell->box->SetBoxExtent(box->GetScaledBoxExtent() / 2);
	_subCell->SetActorLocation(_subLocation);
	cellChildren.Add(_subCell);
	currentNumberOfChildren++;
}

void AOctreeCell::RemoveSubCells()
{
	if (branchingID < 2) return;
	for (int i = 0; i < currentNumberOfChildren; i++)
	{
		AOctreeCell* _cell = cellChildren[i];
		if (!_cell) continue;
		_cell->CustomDestroy();
	}
	cellChildren.Empty();
	currentNumberOfChildren = 0;
}


void AOctreeCell::ManageCellBehaviour(const int _numberOfActorsInside)
{
	if (!octree) return;
	if (_numberOfActorsInside >= cellParameters.capacity && currentNumberOfChildren < 1 && branchingID < octree->GetMaxBranchingID())
	{
		for (int i = 0; i < cellParameters.childrenNumberToSpawn; i++)
		{
			const FVector _subLoc = GetSubLocation(i);
			FVector _loc = FVector(0);
			SubDivideCells(_loc);
		}
	}
}

FVector AOctreeCell::GetSubLocation(const int _index)
{
	float _x = 0,
		  _y = 0,
		  _z = 0;
	if (_index < 4)
	{
		_x = _index == 0 || _index == 2 ? box->Bounds.Origin.X + box->Bounds.BoxExtent.X / 2 : box->Bounds.Origin.X - box->Bounds.BoxExtent.X / 2;
		_y = _index == 0 || _index == 1 ? box->Bounds.Origin.Y + box->Bounds.BoxExtent.Y / 2 : box->Bounds.Origin.Y - box->Bounds.BoxExtent.Y / 2;
		_z = box->Bounds.Origin.Z + box->Bounds.BoxExtent.Z / 2;
	}
	else
	{
		_x = _index == 4 || _index == 6 ? box->Bounds.Origin.X + box->Bounds.BoxExtent.X / 2 : box->Bounds.Origin.X - box->Bounds.BoxExtent.X / 2;
		_y = _index == 4 || _index == 5 ? box->Bounds.Origin.Y + box->Bounds.BoxExtent.Y / 2 : box->Bounds.Origin.Y - box->Bounds.BoxExtent.Y / 2;
		_z = box->Bounds.Origin.Z - box->Bounds.BoxExtent.Z / 2;
	}
	return FVector(_x, _y, _z);
}

void AOctreeCell::DrawDebug()
{
	if (!useDebug) return;
	DrawDebugBox(GetWorld(), box->Bounds.Origin, box->Bounds.BoxExtent, debugColor, false, -1, 0, debugThickness);
}

