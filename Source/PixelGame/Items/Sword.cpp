// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "HUD/MainHUD.h"
#include "Character/PixelGameCharacter.h"
#include "Components/EquipmentComponent.h"

ASword::ASword()
{
	Attacker = nullptr;
	AttackSocket = FName("HitSocket");
	Damage = 2;
	AttackRadius = 5.0f;
	AttackDuration = 0.3f;
	KnockBack = FVector(100.0f, 0.0f, 200.0f);
}

void ASword::Interact(AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("ASword"))
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->EquipmentWidget->Weapon_1->SetBrushResourceObject(Icon);
	Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->EquipmentWidget->Weapon_1->SetBrushTintColor(FLinearColor(1.0f, 1.0f, 1.0f));

	Cast<APixelGameCharacter>(Interactor)->GetEquipmentComponent()->AddEquipmentSlot(ASword::StaticClass(), Category);

	//Cast<UEquipmentComponent>(Interactor->GetComponentByClass(UEquipmentComponent::StaticClass()))->AddEquipmentSlot(/*ASword::StaticClass(), Category*/);

	//UE_LOG(LogTemp, Warning, TEXT("sword")) 
	APickupItem::Interact(Interactor);
}
