// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

AGrid::AGrid()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif

}

void AGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawNodes();
}

void AGrid::Generate()
{
	nodes.Empty();
	for (size_t x = 0; x < size; x++)
	{
		for (size_t y = 0; y < size; y++)
		{
			FVector _pos = FVector(x * gap, y * gap, 0) + GetActorLocation();
			UGridNode* _node = NewObject<UGridNode>(this);
			_node->Init(_pos, this);
			nodes.Add(_node);
		}
	}
	SetSuccessor();
}

void AGrid::ClearGrid()
{
	nodes.Empty();
}

void AGrid::SetSuccessor()
{
	for (size_t i = 0; i < size * size; i++)
	{
		bool _canRight = i % size != size - 1,
			_canTop = i >= size,
			_canDown = i < (size * size) - size,
			_canLeft = i % size != 0;
		if (_canRight) nodes[i]->AddSuccessor(i + 1);
		if (_canLeft) nodes[i]->AddSuccessor(i - 1);
		if (_canTop)
		{
			nodes[i]->AddSuccessor(i - size);
			if (_canRight) nodes[i]->AddSuccessor(i + 1 - size);
			if (_canLeft) nodes[i]->AddSuccessor(i - 1 - size);
		}
		if (_canDown)
		{
			nodes[i]->AddSuccessor(i + size);
			if (_canRight) nodes[i]->AddSuccessor(i + 1 + size);
			if (_canLeft) nodes[i]->AddSuccessor(i - 1 + size);
		}
	}
}


void AGrid::DrawNodes()
{
	for (size_t x = 0; x < size; x++)
	{
		for (size_t y = 0; y < size; y++)
		{
			FVector _pos = FVector(x * gap, y * gap, 0) + GetActorLocation();
			DrawDebugBox(GetWorld(), _pos, FVector(10), FColor::White, false, -1, 0, 2);
		}
	}

	for (size_t i = 0; i < nodes.Num(); i++)
		nodes[i]->DrawDebug(nodeColor, lineColor);
}

bool AGrid::ShouldTickIfViewportsOnly() const
{
	return useDebug;
}


