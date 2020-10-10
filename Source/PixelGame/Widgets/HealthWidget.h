// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/TimelineComponent.h"
#include "Curves/CurveFloat.h"
#include "HealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
//Widgets
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthTransitionBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	class UTextBlock* HealthText;
//Properties
private:
	UPROPERTY()
	int32 PreHealth;
	UPROPERTY()
	int32 TranHealth;
	UPROPERTY()
	int32 CurrentHealth;
	UPROPERTY()
	int32 MaxHealth;
	UPROPERTY()
	float HealthPercent;
	UPROPERTY()
	FText HealthPercentText;
//HealthTransition Helper
private:
	FTimeline HealthTransitionTimeline;
	FOnTimelineFloatStatic HealthTransitionDelegate;

	UPROPERTY(EditAnywhere)
	class UCurveFloat* HealthTransitionCurve;

	UFUNCTION()
	void TransitHealth(float Value);
//Functions
public:
	UFUNCTION()
	void InitializeHealthWidget(int32 InitHealth, int32 InitMaxHealth);
	UFUNCTION()
	void OnCurrentHealthChanged(int32 NewHealth);
};
