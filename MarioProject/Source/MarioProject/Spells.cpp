// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells.h"

FVector USpells::GetSpawnLocation(const float& _angle, const float& _radius) const 
{
    const float _rad = FMath::DegreesToRadians(_angle);
    const float _x = FMath::Cos(_rad) * _radius,
        _y = FMath::Sin(_rad) * _radius;
    return FVector(_x, _y, 0);
}

void USpells::Spawn(UWorld* _world, const FVector& _origin, const float& _yaw)
{
}
