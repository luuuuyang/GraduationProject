// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickupItem.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API ASword : public APickupItem
{
	GENERATED_BODY()

public:
	virtual void Interact(AActor* Interactor) override;
};
