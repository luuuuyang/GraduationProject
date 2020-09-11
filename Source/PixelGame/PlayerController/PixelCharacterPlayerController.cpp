// Fill out your copyright notice in the Description page of Project Settings.


#include "PixelCharacterPlayerController.h"
#include "Character/PixelGameCharacter.h"

void APixelCharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PixelCharacter = Cast<APixelGameCharacter>(GetCharacter());
}

void APixelCharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveRight", this, &APixelCharacterPlayerController::OnMoveLeftRight);
	InputComponent->BindAxis("MoveDown", this, &APixelCharacterPlayerController::OnMoveUpDown);
}

void APixelCharacterPlayerController::OnMoveLeftRight(float Value)
{
	PixelCharacter->MoveLeftRight(Value);
}

void APixelCharacterPlayerController::OnMoveUpDown(float Value)
{
	PixelCharacter->MoveUpDown(Value);
}