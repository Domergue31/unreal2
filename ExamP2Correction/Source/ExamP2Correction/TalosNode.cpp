// Fill out your copyright notice in the Description page of Project Settings.


#include "TalosNode.h"

ATalosNode::ATalosNode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATalosNode::AddLink(ATalosNode* _otherNode)
{
	FString _idConcat = FString::FromInt(id) + FString::FromInt(_otherNode->GetId());
	if (connectedNode.Contains(_idConcat))
	{
		return;
	}
	UTalosLink* _link = NewObject<UTalosLink>(this);
	_link->Connect(this, _otherNode);
	connectedNode.Add(_idConcat, _link);
}

void ATalosNode::NodeBehaviour()
{
	for(TPair<FString, UTalosLink*> _link : connectedNode)
	{
		if (!_link.Value) continue;
		_link.Value->Debug();
		_link.Value->IsValidLink(validNodeLayer);
		_link.Value->Run();
	}
	DrawDebugBox(GetWorld(), GetActorLocation() + GetActorUpVector() * 100, FVector(25), isSource ? FColor::Green : FColor::Red, false, -1, 0, 1);
}

void ATalosNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NodeBehaviour();
}

void ATalosNode::BeginPlay()
{
	Super::BeginPlay();
	id = FMath::Rand();
}
