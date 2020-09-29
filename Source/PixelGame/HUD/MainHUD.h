// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widgets/EquipmentWidget.h"
#include "Widgets/HealthWidget.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API AMainHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UEquipmentWidget> EquipmentWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UHealthWidget> HealthWidgetClass;

public:
	UPROPERTY()
	class UEquipmentWidget* EquipmentWidget;

	UPROPERTY()
	class UHealthWidget* HealthWidget;
};
