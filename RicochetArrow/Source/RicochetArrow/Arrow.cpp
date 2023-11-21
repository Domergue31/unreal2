
#include "Arrow.h"

AArrow::AArrow()
{
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = mesh;
}

void AArrow::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AArrow::Move()
{

}

