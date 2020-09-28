// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/HealthComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* HealthText;

public:
	UFUNCTION()
	void UpdatePercent(float CurrentPercent);

private:
	UPROPERTY()
	int32 CurrentHealth;

	UPROPERTY()
	int32 MaxHealth;	
};
