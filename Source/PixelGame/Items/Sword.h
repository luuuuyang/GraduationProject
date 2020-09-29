// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/PickupItem.h"
#include "Sword.generated.h"

USTRUCT()
struct FMeleeWeaponProperty
{
	GENERATED_BODY()

	UPROPERTY()
	FName AttackSocket;

	UPROPERTY()
	int32 Damage;

	UPROPERTY()
	float AttackRadius;

	UPROPERTY()
	float AttackDuration;

	UPROPERTY()
	FVector KnockBackForce;
};


UCLASS()
class PIXELGAME_API ASword : public APickupItem
{
	GENERATED_BODY()

public:
	ASword();

public:
	virtual void Interact(AActor* Interactor) override;

public:
	FORCEINLINE virtual float GetAttackDuration() override { return WeaponProperty.AttackDuration; }
	
protected:
	UPROPERTY()
	FMeleeWeaponProperty WeaponProperty;

};
