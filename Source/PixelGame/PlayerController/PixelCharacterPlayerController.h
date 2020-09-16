// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/PixelGameCharacter.h"
#include "PixelCharacterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API APixelCharacterPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	UFUNCTION()
	void OnMoveLeftRight(float Value);

	UFUNCTION()
	void OnMoveUpDown(float Value);

	UFUNCTION()
	void OnJump();

	UFUNCTION()
	void OnStopJump();

	UFUNCTION()
	void OnAttack();

	UFUNCTION()
	void OnInteract();

private:
	UPROPERTY()
	APixelGameCharacter* PixelCharacter;
};
