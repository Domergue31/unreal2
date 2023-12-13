
#include "SpawnTool.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetArrayLibrary.h"

ASpawnTool::ASpawnTool()
{
	PrimaryActorTick.bCanEverTick = true;
#if WITH_EDITOR
	PrimaryActorTick.bStartWithTickEnabled = true;
#endif 
	icon = CreateDefaultSubobject<UBillboardComponent>("Icon");
	RootComponent = icon;
}


void ASpawnTool::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnTool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawAllModules();
}

bool ASpawnTool::ShouldTickIfViewportsOnly() const
{
	return true;
}

void ASpawnTool::Spawn()
{
	if (!currentModule)
		return;
	AddNewItems(currentModule->GetModuleName(), currentModule->Spawn(this));
}

void ASpawnTool::Delete()
{
	
	if (historic[currentModule->GetModuleName()].list.IsEmpty())
		return;
	ClearItems(currentModule->GetModuleName());
}

void ASpawnTool::ClearItems(FString _id)
{
	for (size_t i = 0; i < historic[_id].list.Num(); i++)
		historic[_id].list[i]->Destroy();
	historic[_id].list.Empty();
}

void ASpawnTool::DrawAllModules()
{
	if (!currentModule)
		return;
	currentModule->DrawDebug(GetWorld(), GetActorLocation());
}

void ASpawnTool::AddNewItems(FString _id, TArray<AActor*> _items)
{
	if (historic.Contains(_id))
		historic[_id].list.Append(_items);
	else
		historic.Add(_id, _items);
}

TSubclassOf<AActor> ASpawnTool::GetRandomItem()
{
	const int _rnd = FMath::RandRange(0, items.Num() - 1);
	return items[_rnd];
}

