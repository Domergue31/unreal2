// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"
#include "Kismet/KismetSystemLibrary.h"

void UInventory::Add(ACollectibleItem* _item)
{
	UKismetSystemLibrary::PrintString(this, "Add " + _item->GetItemName() + " x " + FString::SanitizeFloat(_item->GetNumber()) + " to inventory");
	ACollectibleItem* _invItem = *inventory.Find(_item->GetItemName());
	if (_invItem)
	{
		_invItem->AddNumber(_item->GetNumber());
		return;
	}
	inventory.Add(_item->GetItemName(), _item);
}

void UInventory::Remove(ACollectibleItem* _item)
{
	inventory.Remove(_item->GetItemName());
}
