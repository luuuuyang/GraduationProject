// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthWidget.h"

void UHealthWidget::UpdateWidget(float CurrentPercent, FText CurrentText)
{
	UpdatePercent(CurrentPercent);
	UpdateText(CurrentText);
}
