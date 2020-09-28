// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "Character/PixelGameCharacter.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	if (EquipmentWidgetClass)
	{
		EquipmentWidget = CreateWidget<UEquipmentWidget>(GetWorld()->GetFirstPlayerController(), EquipmentWidgetClass);
		if (EquipmentWidget)
		{
			EquipmentWidget->AddToViewport();
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

	if (HealthWidgetClass)
	{
		HealthWidget = CreateWidget<UHealthWidget>(GetWorld()->GetFirstPlayerController(), HealthWidgetClass);
		UE_LOG(LogTemp, Warning, TEXT("HealthWidget"))
		if (HealthWidget)
		{
			int32 CurrentHealth = Cast<APixelGameCharacter>(GetOwningPawn())->GetHealthComponent()->GetCurrentHealth();
			int32 MaxHealth = Cast<APixelGameCharacter>(GetOwningPawn())->GetHealthComponent()->GetMaxHealth();
			Cast<APixelGameCharacter>(GetOwningPawn())->GetHealthComponent()->OnHealthChanged.BindUFunction(HealthWidget, "UpdatePercent", 0.5f);
			HealthWidget->HealthBar->SetPercent(CurrentHealth / MaxHealth);
			HealthWidget->AddToViewport();
			
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