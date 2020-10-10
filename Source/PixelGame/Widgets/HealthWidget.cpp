// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthWidget.h"

void UHealthWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	HealthTransitionDelegate.BindUFunction(this, "TransitHealth");
	HealthTransitionTimeline.AddInterpFloat(HealthTransitionCurve, HealthTransitionDelegate);
}

void UHealthWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	HealthTransitionTimeline.TickTimeline(InDeltaTime);
}

void UHealthWidget::TransitHealth(float Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Value = %f"), Value)
	float Pos = HealthTransitionTimeline.GetPlaybackPosition();
	UE_LOG(LogTemp, Warning, TEXT("Pos = %f"), Pos)
	float Alpha = HealthTransitionCurve->GetFloatValue(Pos);
	UE_LOG(LogTemp, Warning, TEXT("Alpha = %f"), Alpha)

	//int32 TransitionalHealth = FMath::Lerp(PreHealth, CurrentHealth, Alpha);
	TranHealth = FMath::Lerp(PreHealth, CurrentHealth, Alpha);
	UE_LOG(LogTemp, Warning, TEXT("%d"), TranHealth)
	float TransitionalHealthPercent = float(TranHealth) / float(MaxHealth);
	HealthTransitionBar->SetPercent(TransitionalHealthPercent);
}

void UHealthWidget::InitializeHealthWidget(int32 InitHealth, int32 InitMaxHealth)
{
	PreHealth = InitHealth;
	TranHealth = InitHealth;
	CurrentHealth = InitHealth;
	MaxHealth = InitMaxHealth;
	HealthPercent = float(CurrentHealth) / float(MaxHealth);
	HealthBar->SetPercent(HealthPercent);
	HealthTransitionBar->SetPercent(HealthPercent);

	if (IsValid(HealthText))
	{
		HealthPercentText = FText::FromString(FString::FromInt(CurrentHealth) + FString(" / ") + FString::FromInt(MaxHealth));
		HealthText->SetText(HealthPercentText);
	}	
}

void UHealthWidget::OnCurrentHealthChanged(int32 NewHealth)
{
	if (HealthTransitionTimeline.IsPlaying())
	{
		PreHealth = TranHealth;
	}
	else
	{
		PreHealth = CurrentHealth;
	}
	
	CurrentHealth = NewHealth;
	HealthPercent = float(CurrentHealth) / float(MaxHealth);
	HealthBar->SetPercent(HealthPercent);
	
	HealthTransitionTimeline.PlayFromStart();

	if (IsValid(HealthText))
	{
		HealthPercentText = FText::FromString(FString::FromInt(CurrentHealth) + FString(" / ") + FString::FromInt(MaxHealth));
		HealthText->SetText(HealthPercentText);
	}
}
