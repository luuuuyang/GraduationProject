// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemInteractionInterface.h"

// Add default functionality here for any IItemInteractionInterface functions that are not pure virtual.

void IItemInteractionInterface::Interact(AActor* Interactor)
{
	UE_LOG(LogTemp, Warning, TEXT("IItemInteractionInterface"))
}

void IItemInteractionInterface::Overlap(AActor* Actor)
{

}