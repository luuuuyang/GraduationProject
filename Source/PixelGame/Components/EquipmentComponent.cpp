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

	//EquipmentSlots.Init(FEquipmentSlot(), 4);

	//A = APickupItem::StaticClass();

	//EquipmentSlot.EquipmentClass = nullptr;

	//EquipmentSlot.EquipmentClass = ASword::StaticClass();

	//if (EquipmentSlot.EquipmentClass)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("EquipmentClass is not null"))
	//}
	// ...
}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	
	//A = APickupItem::StaticClass();
}


// Called every frame
void UEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEquipmentComponent::AddEquipmentSlot(TSubclassOf<APickupItem> PickupItemClass, PickupItemCategory Category)
{
	
	EquipmentSlots.Emplace(FEquipmentSlot(PickupItemClass, Category));

	//EquipmentSlots.Add(FEquipmentSlot(/*PickupItemClass, */Category));
	UE_LOG(LogTemp, Warning, TEXT("Add Equipment Slot Success"))
}

bool UEquipmentComponent::IsEquipmentSlotEmpty()
{
	return false;
}

void UEquipmentComponent::UseEquipmentSlot(int32 Index)
{

}