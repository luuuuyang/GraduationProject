// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "HUD/MainHUD.h"
#include "Character/PixelGameCharacter.h"
#include "Components/EquipmentComponent.h"
#include "Components/AttackComponent.h"

ASword::ASword()
{
	WeaponProperty.AttackSocket = FName("HitSocket");
	WeaponProperty.Damage = 2;
	WeaponProperty.AttackRadius = 5.0f;
	WeaponProperty.AttackDuration = 0.4f;
	WeaponProperty.KnockBackForce = FVector(100.0f, 0.0f, 200.0f);
}

void ASword::Interact(AActor* Interactor)
{
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->EquipmentWidget->Weapon_1->SetBrushResourceObject(Icon);
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->EquipmentWidget->Weapon_1->SetBrushTintColor(FLinearColor(1.0f, 1.0f, 1.0f));
	
	Cast<APixelGameCharacter>(Interactor)->GetEquipmentComponent()->AddEquipmentSlot(ASword::StaticClass(), Category);
	Cast<APixelGameCharacter>(Interactor)->GetAttackComponent()->SetMeleeWeaponProperty(WeaponProperty);

	APickupItem::Interact(Interactor);
}
