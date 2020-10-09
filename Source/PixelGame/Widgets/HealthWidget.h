// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "HealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UTextBlock* HealthText;

private:
	UPROPERTY()
	int32 CurrentHealth;

	UPROPERTY()
	int32 MaxHealth;

	UPROPERTY()
	float HealthPercent;

	UPROPERTY()
	FText HealthPercentText;

public:
	UFUNCTION()
	void InitializeHealthWidget(int32 InitCurrentHealth, int32 InitMaxHealth);

	UFUNCTION()
	void OnCurrentHealthChanged(int32 NewCurrentHealth);
};
