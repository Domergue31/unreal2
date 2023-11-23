// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractItem.h"

void AInteractItem::BeginPlay()
{
	Super::BeginPlay();
	dynamicMaterialColor = GetStaticMeshComponent()->CreateDynamicMaterialInstance(0);
	FHashedMaterialParameterInfo _param;
	_param.Name = FScriptName("InteractColor");
	dynamicMaterialColor->GetVectorParameterValue(_param, defaultColor);
}

void AInteractItem::ApplyInteractColor()
{
	dynamicMaterialColor->SetVectorParameterValue("InteractColor", interactColor);
}

void AInteractItem::ResetDefaultColor()
{
	dynamicMaterialColor->SetVectorParameterValue("InteractColor", defaultColor);
}

