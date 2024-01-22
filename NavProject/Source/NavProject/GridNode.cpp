// Fill out your copyright notice in the Description page of Project Settings.


#include "GridNode.h"
#include "Grid.h"

void UGridNode::Init(FVector _pos, AGrid* _grid)
{
	position = _pos;
	grid = _grid;
}

void UGridNode::DrawDebug(FColor _nodeColor, FColor _lineColor)
{
	DrawDebugSphere(GetWorld(), position, 30, 20, _nodeColor, false, -1, 0, 2);

	for (size_t i = 0; i < successor.Num(); i++)
		DrawDebugLine(GetWorld(), position, grid->Nodes()[successor[i]]->Position(), _lineColor, false, -1, 0, 3);
}
