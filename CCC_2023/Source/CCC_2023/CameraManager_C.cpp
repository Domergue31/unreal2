// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManager_C.h"

bool UCameraManager_C::AddCamera(UCameraManagedComponent_C* _camera)
{
	if (cameras.Contains(_camera->ID().ToLower()))
		return false;
	cameras.Add(_camera->ID().ToLower(), _camera);
	return true;
}

bool UCameraManager_C::RemoveCamera(UCameraManagedComponent_C* _camera)
{
	cameras.Remove(_camera->ID().ToLower());
	return true;
	return cameras.Contains(_camera->ID().ToLower());
}

void UCameraManager_C::DisableCamera(FString _id)
{
	UCameraManagedComponent_C** _camera = cameras.Find(_id.ToLower());
	if (!_camera)
		return;
	(*_camera)->Disable();
	//cameras[_id.ToLower()]->Disable();
}

void UCameraManager_C::EnableCamera(FString _id)
{
	UCameraManagedComponent_C** _camera = cameras.Find(_id.ToLower());
	if (!_camera)
		return;
	(*_camera)->Enable();
	//cameras[_id.ToLower()]->Enable();
}

void UCameraManager_C::SpawnCameraFollow(FString _id, AActor* _target)
{
	SpawnCamera<ACameraFollow>(cameraFollowDefault, _id, _target);
}

void UCameraManager_C::SpawnOrbitCamera(FString _id, AActor* _target)
{
	SpawnCamera<AOrbitCamera>(orbitCameradefault, _id, _target);
}
