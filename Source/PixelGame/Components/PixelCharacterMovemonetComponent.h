// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Character/PixelGameCharacter.h"
#include "PixelCharacterMovemonetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXELGAME_API UPixelCharacterMovemonetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPixelCharacterMovemonetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION()
	void MoveLeftRight(APixelGameCharacter* PixelCharacter, float Value);

	UFUNCTION()
	void MoveUpDown(APixelGameCharacter* PixelCharacter, float Value);

	UFUNCTION()
	void Jump(APixelGameCharacter* PixelCharacter);

	UFUNCTION()
	void StopJump(APixelGameCharacter* PixelCharacter);

};
