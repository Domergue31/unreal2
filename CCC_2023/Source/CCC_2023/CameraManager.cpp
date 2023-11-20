#include "CameraManager.h"

ACameraManager::ACameraManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACameraManager::Register(UCameraManagedComponent* _camera)
{
	if (items.Contains(_camera->GetCameraID()))
		return;
	items.Add(_camera->GetCameraID(), _camera);
}

void ACameraManager::UnRegister(UCameraManagedComponent* _camera)
{
	if (!items.Contains(_camera->GetCameraID()))
		return;
	items.Remove(_camera->GetCameraID());
}


