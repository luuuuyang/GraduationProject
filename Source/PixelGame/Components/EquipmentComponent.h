// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Blueprint/UserWidget.h"
#include "Items/PickupItem.h"
#include "Items/Sword.h"
#include "EquipmentComponent.generated.h"

USTRUCT()
struct FEquipmentSlot
{
	GENERATED_BODY()

	UPROPERTY()
	TSubclassOf<APickupItem> EquipmentClass;

	UPROPERTY()
	PickupItemCategory EquipmentCategory;


	FEquipmentSlot()
	{
		EquipmentClass = APickupItem::StaticClass();
		EquipmentCategory = PickupItemCategory::NONE;
	}

	FEquipmentSlot(TSubclassOf<APickupItem> Class, PickupItemCategory Category)
	{
		EquipmentClass = Class;
		EquipmentCategory = Category;
	}

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXELGAME_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEquipmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY()
		TArray<TSubclassOf<APickupItem>> PotionSlots;

	UPROPERTY()
		TArray<TSubclassOf<APickupItem>> WeaponSlots;

	UPROPERTY()
		TArray<TSubclassOf<APickupItem>> AbilitySlots;

private:

public:

	//根据拾起物品的类别分别放在不同的插槽中
	UFUNCTION()
	void AddEquipmentSlot(TSubclassOf<APickupItem> PickupItemClass, PickupItemCategory Category);

	UFUNCTION()
	void SwapEquipmentSlot();

	UFUNCTION()
	bool IsPotionSlotValid(int32 Index);

	UFUNCTION()
	bool IsWeaponSlotValid(int32 Index);

	UFUNCTION()
	bool IsAbilitySlotValid(int32 Index);

	UFUNCTION()
	void UseEquipmentSlot(int32 Index);

	UFUNCTION()
	float GetWeaponAttackDuration(int32 Index);

};
