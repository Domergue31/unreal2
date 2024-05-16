#include "CWP_Octree.h"
#include "CWP_StreamManagerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/BrushComponent.h"

ACWP_Octree::ACWP_Octree()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

#pragma region Engine

void ACWP_Octree::OnConstruction(const FTransform& _transform)
{
	Super::OnConstruction(_transform);
	
	const FVector& _scale = boxScale / 2.0f;
	const FVector& _min = GetActorLocation() - _scale;
	const FVector& _max = GetActorLocation() + _scale;
	box = FBox(_min, _max);
}

void ACWP_Octree::BeginPlay()
{
	Super::BeginPlay();
	if (isMaster)
	{
		if (UCWP_StreamManagerSubsystem* _manager = GetWorld()->GetSubsystem<UCWP_StreamManagerSubsystem>())
			_manager->SetOctree(this);
	}
	if (isMaster)
		Update();
}

void ACWP_Octree::Tick(float _deltaTime)
{
	Super::Tick(_deltaTime);
	DrawOctrees();
}

#if WITH_EDITOR
bool ACWP_Octree::ShouldTickIfViewportsOnly() const
{
	return debugSettings.showDebug;
}

void ACWP_Octree::PostEditChangeProperty(FPropertyChangedEvent& _event)
{
	Super::PostEditChangeProperty(_event);

	if (_event.Property->GetFName() == FName("capacity"))
	{
		Update();
	}
}
#endif
#pragma endregion 

#pragma region Tool

void ACWP_Octree::Update()
{
	// Clear all children
	Clear();

	// Used to compare the quantity of actors contained into this Octree
	bool _amountReduced = true;

	if (isMaster)
	{
		// Get all meshes in the world
		GetActors();

		// Set the minimum capacity of actors for his children
		capacityMin = actors.Num() * 1 / 100;
	}

	else
	{
		// Clamp the current capacity of actors this octree can contains
		capacity = capacity < master->capacityMin ? master->capacityMin : capacity;

		// Store actors before
		const int _parentActorsCount = actors.Num();

		// Get all meshes in the world
		GetActors();

		// Take the current number of actors to compare
		_amountReduced = actors.Num() < _parentActorsCount;
	}

	// If there is to many meshes, subdivide them in different octree
	if (actors.Num() > capacity && _amountReduced)
	{
		SpawnChildren();
	}

	else if (master)
	{
		// Add this octree to manage it
		master->AddOctreeWithoutChildren(this);
	}
}

void ACWP_Octree::SwitchVisibility()
{
	// Switch current visibility
	debugSettings.showDebug = !debugSettings.showDebug;

	// Check if this octree has children
	if (HasChildren())
	{
		// Iterate all children
		const int& _childrenCount = octreeChildren.Num();
		for (int _childIndex(0); _childIndex < _childrenCount; _childIndex++)
		{
			// Get the current octree
			ACWP_Octree* _octree = octreeChildren[_childIndex];
			if (!_octree) continue;

			// Change his visibility
			_octree->SwitchVisibility();
		}
	}
}

void ACWP_Octree::Clear()
{
	// Do this only for the first one
	if (isMaster)
	{
		actors.Empty();
		octreesWithoutChildren.Empty();
		master = this;
	}

	// Reset all octrees and meshes
	ResetOctree();
}

#pragma endregion

#pragma region Common

void ACWP_Octree::DrawOctrees() const
{
	if (!debugSettings.showDebug) return;

	// Draw current octree as box
	DrawDebugBox(GetWorld(), box.GetCenter(), box.GetExtent(), debugSettings.lineColor, false, -1, 0, debugSettings.thickness);
}

void ACWP_Octree::GetActors()
{
	TArray<AActor*> _allActors;

	// Do this only for the first one
	if (accuracy <= 1)
	{
		// Get all actors in the world
		//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), _allActors);

		// Get all actors attached to this
		GetAttachedActors(_allActors);
	}

	// Otherwise get all actors of the owner
	else
	{
		// Get all parent's actors before empty it
		const int& _actorsCount = actors.Num();
		for (int _actorIndex(0); _actorIndex < _actorsCount; _actorIndex++)
		{
			TSoftObjectPtr<AActor> _actor = actors[_actorIndex];
			if (!_actor) continue;
			_allActors.Add(_actor.Get());
		}

		// Reset his actors before filling it again
		actors.Empty();
	}

	// Iterate all actors
	const int& _actorsCount = _allActors.Num();
	for (int _actorIndex(0); _actorIndex < _actorsCount; _actorIndex++)
	{
		// Get the current actor
		AActor* _actor = _allActors[_actorIndex];
		if (!_actor) continue;

		// Check if this actor is into the current Octree
		const FBox& _actorBoundingBox = _actor->GetComponentsBoundingBox();
		if (!box.Intersect(_actorBoundingBox)) continue;

		// Check if this actor hasn't a static mesh and must be hidden
		if (!HasStaticMesh(_actor) || actorsToIgnore.Contains(_actor)) continue;

		// // Check if this actor contains a static mesh
		if (!_actor->GetComponentByClass(UActorComponent::StaticClass())) continue;

		// Then add it to actors
		actors.Add(_actor);
	}
}

bool ACWP_Octree::HasStaticMesh(AActor* _actor)
{
	// Retrieve all static meshes
	TArray<UActorComponent*> _components;
	_actor->GetComponents(UStaticMeshComponent::StaticClass(), _components, true);

	const int _componentsCount = _components.Num();
	for (int _componentIndex = 0; _componentIndex < _componentsCount; _componentIndex++)
	{
		// Get the next ActorComponent
		const UActorComponent* _component = _components[_componentIndex];
		if (!_component) return false;

		// Check if it is a StaticMesh
		if (_component->IsA<UStaticMeshComponent>()) return true;
	}

	return false;
}

void ACWP_Octree::SpawnChildren()
{
	// Check if the TSubclassOf is well defined
	if (!IsValid(octreeType))
	{
		// Otherwise, warn the user to set it
		UE_LOG(LogTemp, Warning, TEXT("You have forgot to set an OctreeType !"))
			return;
	}

	// Iterate 8 times (=> Octree)
	for (int _childIndex(0); _childIndex < 8; _childIndex++)
	{
		// Spawn a new octree
		ACWP_Octree* _child = GetWorld()->SpawnActor<ACWP_Octree>(octreeType);
		if (!_child) continue;
		_child->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		// Get the center and extent of the current bounding box
		FVector _initialExtent = box.GetExtent();

		// Compute the new octree's values
		FVector _extent;
		_extent.X = _childIndex % 2 == 0 ? 0 : _initialExtent.X;
		_extent.Y = _childIndex % 4 >= 2 ? _initialExtent.Y : 0;
		_extent.Z = _childIndex >= 4 ? _initialExtent.Z : 0;

		const int& _accuracy = accuracy + 1;
		const FVector& _min = box.Min + _extent;
		const FVector& _max = _min + _initialExtent;

		// Setup the new child with some parameters
		_child->Setup(_accuracy, capacity, FBox(_min, _max), master, actors);

		// Add it to the children
		octreeChildren.Add(_child);

		// Init the new octree
		_child->Update();
	}
}

void ACWP_Octree::ResetOctree()
{
	// Iterate all children
	const int& _childCount = octreeChildren.Num();
	for (int _childIndex(0); _childIndex < _childCount; _childIndex++)
	{
		// Get each children
		ACWP_Octree* _octree = octreeChildren[_childIndex];
		if (!_octree) continue;

		// Destroy children
		_octree->ResetOctree();

		// Destroy this octree
		_octree->Destroy();
	}

	// Clear all actors and children stored 
	octreeChildren.Empty();
}

void ACWP_Octree::ChangeVisibility(const bool _status)
{
	FColor _color = _status ? FColor::Green : FColor::Red;
	DrawDebugBox(GetWorld(), box.GetCenter(), box.GetExtent() * 80 / 100.0f, _color, false, -1.0f, 0, 3.0f);
	_color.A = 30;
	DrawDebugSolidBox(GetWorld(), box.GetCenter(), box.GetExtent() * 80 / 100.0f, _color);

	const int _actorsCount = actors.Num();
	for (int _index = 0; _index < _actorsCount; _index++)
	{
		AActor* _actor = actors[_index].Get();
		USceneComponent* _sceneComponent = _actor->GetRootComponent();
		_sceneComponent->SetVisibility(_status, true);
		_actor->SetActorEnableCollision(_status);
	}
}

// Deprecated : Use with world partition
void ACWP_Octree::Place(const FVector& _location, const float _size)
{
	SetActorLocation(_location);

	const FVector& _extent = FVector(_size, _size, _size);
	boxScale = _extent;

	OnConstruction(GetTransform());
}

#pragma endregion