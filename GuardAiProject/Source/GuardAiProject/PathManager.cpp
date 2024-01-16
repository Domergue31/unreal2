

#include "PathManager.h"

bool UPathManager::Register(APath* _path)
{
	if (paths.Contains(_path))
		return false;
	paths.Add(_path);
	return true;
}

bool UPathManager::UnRegister(APath* _path)
{
	if (!paths.Contains(_path))
		return false;
	paths.Remove(_path);
	return true;
}

APath* UPathManager::GetNearestPath(FVector _pos)
{
	if (paths.Num() == 0)
		return nullptr;
	float _distance = 0;
	APath* _tmp = nullptr;
	for (APath* _path : paths)
	{
		AWaypoint* _waypoint = _path->GetStartingPoint();
		if (_waypoint && FVector::Distance(_waypoint->GetActorLocation(), _pos) < _distance || _waypoint && !_tmp)
		{
			_distance = FVector::Distance(_waypoint->GetActorLocation(), _pos);
			_tmp = _path;
		}
	}
	return _tmp;
	
}
