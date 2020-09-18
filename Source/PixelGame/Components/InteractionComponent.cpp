// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interfaces/ItemInteractionInterface.h"
#include "Items/PickupItem.h"
#include "Items/Sword.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractionComponent::InteractEvent(TArray<AActor*> OverlappingActors)
{
	for (auto Actors : OverlappingActors)
	{
		if (Actors->GetClass()->ImplementsInterface(UItemInteractionInterface::StaticClass()))
		{
			Cast<ASword>(Actors)->Interact(GetOwner());
		}
	}
}
