// Fill out your copyright notice in the Description page of Project Settings.


#include "LineSpawnModule.h"
#include "SpawnTool.h"

void ULineSpawnModule::DrawDebug(UWorld* _world, const FVector& _origin)
{
	for (size_t i = 0; i < itemNumber * gap; i+= gap)
	{
		const FVector _point = _origin + FVector(0, i, 0);
		DrawDebugSphere(_world, _point, 50, 20, FColor::Red, false, -1, 0, 2);
	}
}

TArray<AActor*> ULineSpawnModule::Spawn(ASpawnTool* _tool)
{
	TArray<AActor*> _items = {};
	for (size_t i = 0; i < itemNumber * gap; i += gap)
	{
		const FVector _point = _tool->GetActorLocation() + FVector(0, i, 0);
		AActor* _item = _tool->GetWorld()->SpawnActor<AActor>(_tool->PickItem(), _point, FRotator());
		_items.Add(_item);
	}
	return _items;
}
