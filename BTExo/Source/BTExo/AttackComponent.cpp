// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!canAttack)
		UpdateTime(currentTime, maxTime);
	isInRange = CheckIsInRange(attackRange);

}

void UAttackComponent::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack Tentative"));
	if (!isInRange || !canAttack || !target) return;
	canAttack = false;
	const FVector _startLoc = GetOwner()->GetActorLocation();
	const FVector _dir = GetOwner()->GetActorForwardVector();
	FRotator _rot = GetOwner()->GetActorRotation();
	FHitResult _result;
	bool _hit = UKismetSystemLibrary::BoxTraceSingleForObjects(GetWorld(), _startLoc + _dir * boxOffset, _startLoc + _dir * boxOffset, FVector(attackBoxSize), _rot,
		layerToAttack, false, { GetOwner() }, EDrawDebugTrace::ForDuration, _result, false, FLinearColor::Yellow, FLinearColor::Red, 1);
	if (!_hit) return;
	AActor* _target = _result.GetActor();
	if (!_target) return;
	UE_LOG(LogTemp, Error, TEXT("Attack Done"));
	//TODO Deal Damage
}

float UAttackComponent::UpdateTime(float& _current, const float& _max)
{
	_current += GetWorld()->DeltaTimeSeconds * attackSpeed;
	if (_current >= _max)
	{
		canAttack = true;
		_current = 0;
	}
	return _current;
}

bool UAttackComponent::CheckIsInRange(const float& _range)
{
	if (!target) return false;
	float _distance = FVector::Distance(GetOwner()->GetActorLocation(), target->GetActorLocation());
	const bool _value = _distance <= _range;
	onRangeUpdate.Broadcast(_value);
	return _value;
}

void UAttackComponent::SetTarget(AActor* _target)
{
	target = _target;
}
