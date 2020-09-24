// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickupItem.h"
#include "PaperFlipbookComponent.h"
#include "Sword.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API ASword : public APickupItem
{
	GENERATED_BODY()

public:
	ASword();

public:
	virtual void Interact(AActor* Interactor) override;

	FORCEINLINE virtual float GetAttackDuration() override { return AttackDuration; }
	
protected:
	UPROPERTY(EditAnywhere)
	class UPaperFlipbookComponent* Attacker;

	UPROPERTY(EditAnywhere)
	FName AttackSocket;

	UPROPERTY(EditAnywhere)
	int32 Damage;

	UPROPERTY(EditAnywhere)
	float AttackRadius;
	
	UPROPERTY(EditAnywhere)
	float AttackDuration;

	UPROPERTY(EditAnywhere)
	FVector KnockBack;

};
