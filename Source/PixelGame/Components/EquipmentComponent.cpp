// Fill out your copyright notice in the Description page of Project Settings.


#include "EquipmentComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/Image.h"

struct FEquipmentSlot;

// Sets default values for this component's properties
UEquipmentComponent::UEquipmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEquipmentComponent::AddEquipmentSlot(TSubclassOf<APickupItem> PickupItemClass, PickupItemCategory Category)
{
	/*switch (Category)
	{
	case PickupItemCategory::NONE:
		break;
	case PickupItemCategory::POTION:
		PotionSlots.Emplace(PickupItemClass);
		break;
	case PickupItemCategory::MELEEWEAPON:
		WeaponSlots.Emplace(PickupItemClass);
		break;
	case PickupItemCategory::MELEEWEAPON:
		WeaponSlots.Emplace(PickupItemClass);
		break;
	case PickupItemCategory::ABILITY:
		AbilitySlots.Emplace(PickupItemClass);
		break;
	case PickupItemCategory::LOOT:
		break;
	default:
		break;
	}*/

	WeaponSlots.Emplace(FEquipmentSlot(PickupItemClass, Category));
	
	
}

void UEquipmentComponent::SwapEquipmentSlot()
{
}

/*bool UEquipmentComponent::IsPotionSlotValid(int32 Index)
{
	return PotionSlots.IsValidIndex(Index);
}*/

bool UEquipmentComponent::IsWeaponSlotValid(int32 Index)
{
	return WeaponSlots.IsValidIndex(Index);
}

/*bool UEquipmentComponent::IsAbilitySlotValid(int32 Index)
{
	return AbilitySlots.IsValidIndex(Index);
}*/

void UEquipmentComponent::UseEquipmentSlot(int32 Index)
{

}

float UEquipmentComponent::GetWeaponAttackDuration(int32 Index)
{
	return Cast<APickupItem>(WeaponSlots[Index].EquipmentClass.GetDefaultObject())->GetAttackDuration();
}

TSubclassOf<APickupItem> UEquipmentComponent::GetWeaponClass(int32 Index)
{
	return WeaponSlots[Index].EquipmentClass;
}

PickupItemCategory UEquipmentComponent::GetWeaponCategory(int32 Index)
{
	return WeaponSlots[Index].EquipmentCategory;
}
