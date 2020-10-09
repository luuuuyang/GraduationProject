// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthWidget.h"

void UHealthWidget::InitializeHealthWidget(int32 InitCurrentHealth, int32 InitMaxHealth)
{
	CurrentHealth = InitCurrentHealth;
	MaxHealth = InitMaxHealth;
	HealthPercent = float(CurrentHealth) / float(MaxHealth);
	HealthBar->SetPercent(HealthPercent);

	if (IsValid(HealthText))
	{
		HealthPercentText = FText::FromString(FString::FromInt(CurrentHealth) + FString(" / ") + FString::FromInt(MaxHealth));
		HealthText->SetText(HealthPercentText);
	}
}

void UHealthWidget::OnCurrentHealthChanged(int32 NewCurrentHealth)
{
	CurrentHealth = NewCurrentHealth;
	HealthPercent = float(CurrentHealth) / float(MaxHealth);

	UE_LOG(LogTemp, Warning, TEXT("after %d"), NewCurrentHealth)
	HealthBar->SetPercent(HealthPercent);

	if (IsValid(HealthText))
	{
		HealthPercentText = FText::FromString(FString::FromInt(CurrentHealth) + FString(" / ") + FString::FromInt(MaxHealth));
		HealthText->SetText(HealthPercentText);
	}
}
