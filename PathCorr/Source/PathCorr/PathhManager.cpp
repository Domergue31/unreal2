// Fill out your copyright notice in the Description page of Project Settings.


#include "PathhManager.h"
#include "PathActor.h"

void UPathhManager::AddPath(APathActor* _path)
{
	allPaths.Add(_path);
}

APathActor* UPathhManager::GetPath() const
{
	const int _randIndex = FMath::RandRange(0, allPaths.Num() - 1);
	if (_randIndex < 0)
		return nullptr;
	return allPaths[_randIndex];
}
