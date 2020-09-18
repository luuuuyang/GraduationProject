// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("HUD begin play"))


	if (WidgetClass)
	{
		EquipmentWidget = CreateWidget<UEquipmentWidget>(GetWorld()->GetFirstPlayerController(), WidgetClass);
		if (EquipmentWidget)
		{
			EquipmentWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("Widget created"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Widget failure"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Class failure"))
	}
}