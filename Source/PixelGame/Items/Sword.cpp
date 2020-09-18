// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "HUD/MainHUD.h"

void ASword::Interact(AActor* Interactor)
{
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->EquipmentWidget->Weapon_1->SetBrushResourceObject(Icon);
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->EquipmentWidget->Weapon_1->SetBrushTintColor(FLinearColor(1.0f, 1.0f, 1.0f));
	UE_LOG(LogTemp, Warning, TEXT("sword"))
	APickupItem::Interact(Interactor);
}
