// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.h"
#include "Interfaces/ItemInteractionInterface.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "PickupItem.generated.h"

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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	TSubclassOf<AItemBase> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	bool bCanReplaceFlipbookWithItemFlipbook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOverlapping;

public:
	virtual void Interact(AActor* Interactor) override;
};
