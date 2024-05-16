#include "CWP_StreamingSourceComponent.h"
#include "CWP_Octree.h"
#include "CWP_StreamManagerSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"

UCWP_StreamingSourceComponent::UCWP_StreamingSourceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCWP_StreamingSourceComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UCWP_StreamManagerSubsystem* _manager = GetWorld()->GetSubsystem<UCWP_StreamManagerSubsystem>())
		_manager->Register(this);
}

TArray<ACWP_Octree*> UCWP_StreamingSourceComponent::UpdateStreaming(ACWP_Octree* _octreeMaster)
{
	if (!_octreeMaster) return TArray<ACWP_Octree*>();

	TArray<ACWP_Octree*> _validOctrees;
	FSphere _sphere = FSphere(GetOwner()->GetActorLocation(), radius);
	TArray<ACWP_Octree*> _allChildren = _octreeMaster->GetOctreesWithoutChildren();
	const int _childrenCount = _allChildren.Num();

	for (int _index = 0; _index < _childrenCount; _index++)
	{
		ACWP_Octree* _octree = _allChildren[_index];
		const FBox& _box = _octree->GetBox();
		const bool _interects = FMath::SphereAABBIntersection(_sphere, _box);
		//_octree->ChangeVisibility(_interects);
		if (_interects)
		{
			_validOctrees.Add(_octree);
		}
	}

	DrawDebugSphere(GetWorld(), _sphere.Center, radius, 12, FColor::Blue);

	return _validOctrees;
}