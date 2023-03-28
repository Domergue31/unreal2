// Fill out your copyright notice in the Description page of Project Settings.


#include "FireBall.h"

void UFireBall::Spawn(UWorld* _world, const FVector& _origin, const float& _yaw)
{
	const float _angle = _yaw;
	const FVector _location = GetSpawnLocation(_angle, radius) + _origin;
	AProjectiles* _projectile = _world->SpawnActor<AProjectiles>(projectile, _location, FRotator(0, _yaw, 0));
	_projectile->InitProjectile(lifeSpan);
}
