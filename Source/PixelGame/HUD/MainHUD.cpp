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
			UE_LOG(LogTemp, Warning, TEXT("EquipmentWidget Create Success"))
			EquipmentWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("EquipmentWidget Create Failure"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EquipmentWidgetClass Empty"))
	}

	if (HealthWidgetClass)
	{
		HealthWidget = CreateWidget<UHealthWidget>(GetWorld()->GetFirstPlayerController(), HealthWidgetClass);
		if (HealthWidget)
		{
			APixelGameCharacter* MyCharacter = Cast<APixelGameCharacter>(GetOwningPawn());

			MyCharacter->GetHealthComponent()->OnHealthChanged.BindUFunction(HealthWidget, "UpdateWidget");


			float HealthPercent = MyCharacter->GetHealthComponent()->GetHealthPercent();
			HealthWidget->HealthBar->SetPercent(HealthPercent);

			int32 CurrentHealth = MyCharacter->GetHealthComponent()->GetCurrentHealth();
			int32 MaxHealth = MyCharacter->GetHealthComponent()->GetMaxHealth();
			FString FormatHealthText = FString::FromInt(CurrentHealth) + FString(" / ") + FString::FromInt(MaxHealth);
			HealthWidget->HealthText->SetText(FText::FromString(FormatHealthText));

			HealthWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HealthWidget Create Failure"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HealthWidgetClass Empty"))
	}
}