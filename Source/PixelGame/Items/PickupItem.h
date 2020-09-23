// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ItemInteractionInterface.h"
#include "PaperFlipbookComponent.h"
#include "PaperSprite.h"
#include "Components/BoxComponent.h"
#include "PickupItem.generated.h"

UENUM(BlueprintType)
enum class PickupItemCategory : uint8
{
	NONE UMETA(DisplayName = "None"),
	WEAPON UMETA(DisplayName = "Weapon"),
	ABILITY UMETA(DisplayName = "Ability"),
	POTION UMETA(DisplayName = "Potion"),
	LOOT UMETA(DisplayName = "Loot")
};


UCLASS()
class PIXELGAME_API APickupItem : public AActor, public IItemInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* PaperFlipbook;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* Box;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSprite* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	PickupItemCategory Category;

public:
	virtual void Interact(AActor* Interactor) override;
};
