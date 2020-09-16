// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperFlipbook.h"
#include "ItemBase.generated.h"

UENUM()
enum class ItemCategory
{
	WEAPON UMETA(DisplayName = "Weapon"),
	ABILITY UMETA(DisplayName = "Ability")
};

USTRUCT(BlueprintType)
struct FItemInformation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSprite* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperFlipbook* Flipbook;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Useable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText UseString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Stackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StackSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ItemCategory Category;
};

UCLASS()
class PIXELGAME_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawnedB
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItemInformation info;
	
};
