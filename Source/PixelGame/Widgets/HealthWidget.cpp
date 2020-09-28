// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthWidget.h"
#include "Character/PixelGameCharacter.h"

void UHealthWidget::UpdatePercent(float CurrentPercent)
{
	HealthBar->SetPercent(CurrentPercent);
}
