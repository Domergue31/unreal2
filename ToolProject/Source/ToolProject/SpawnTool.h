// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnModule.h"
#include "Components/BillBoardComponent.h"
#include "SpawnTool.generated.h"


USTRUCT()
struct FArray
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		TArray<AActor*> list;
	FArray() {}
	FArray(TArray<AActor*> _items)
	{
		list = _items;
	}
};

UCLASS()
class TOOLPROJECT_API ASpawnTool : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Spawn Tool")
		TObjectPtr<UBillboardComponent> icon = nullptr;
	UPROPERTY(EditAnywhere, Category = "Spawn Tool")
		TObjectPtr<USpawnModule> currentModule = nullptr;
	UPROPERTY(EditAnywhere, Category = "Spawn Tool")
		bool useSingleItem = true;
	UPROPERTY(EditAnywhere, Category = "Spawn Tool", meta = (EditCondition = "useSingleItem"))
		TSubclassOf<AActor> item = nullptr;
	UPROPERTY(EditAnywhere, Category = "Spawn Tool", meta = (EditCondition = "!useSingleItem"))
		TArray<TSubclassOf<AActor>> items = {};
	UPROPERTY(EditAnywhere, Category = "Spawn Tool")
	TMap<FString, FArray> historic = {};
	
public:	
	ASpawnTool();
	TSubclassOf<AActor> PickItem() { return useSingleItem ? item : GetRandomItem(); }
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool ShouldTickIfViewportsOnly()  const override;

	UFUNCTION(CallInEditor, Category = "Spawn Tool")void Spawn();
	UFUNCTION(CallInEditor, Category = "Spawn Tool")void Delete();
	void ClearItems(FString _id);
	void DrawAllModules();
	void AddNewItems(FString _id, TArray<AActor*> _items);
	TSubclassOf<AActor> GetRandomItem();
};
