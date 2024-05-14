// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointManager.h"

bool UWaypointManager::Register(AWaypoint* _point)
{
	if (points.Contains(_point))
		return false;
	points.Add(_point);
	return true;
}

bool UWaypointManager::UnRegister(AWaypoint* _point)
{
	if (!points.Contains(_point))
		return false;
	points.Remove(_point);
	return true;
}

AWaypoint* UWaypointManager::GetNearestPoint(FVector _pos)
{
	if (points.Num() == 0)
		return nullptr;

	float _distance = FVector::Distance(_pos, points[0]->GetActorLocation());
	AWaypoint* _tmp = points[0];

	for (size_t i = 1; i < points.Num(); i++)
	{
		const float _distTemp = FVector::Distance(_pos, points[i]->GetActorLocation());
		if (_distTemp < _distance && points[i]->GetPathOwner())
		{
			_distance = _distTemp;
			_tmp = points[i];
		}
	}
	return _tmp;
}
