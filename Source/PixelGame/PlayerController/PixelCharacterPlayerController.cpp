// Fill out your copyright notice in the Description page of Project Settings.


#include "PixelCharacterPlayerController.h"
#include "Character/PixelGameCharacter.h"
#include "HUD/MainHUD.h"

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

	InputComponent->BindAction("Jump", IE_Pressed, this, &APixelCharacterPlayerController::OnJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APixelCharacterPlayerController::OnStopJump);

	InputComponent->BindAction("Attack", IE_Pressed, this, &APixelCharacterPlayerController::OnAttack);

	InputComponent->BindAction("Interact", IE_Pressed, this, &APixelCharacterPlayerController::OnInteract);
}

void APixelCharacterPlayerController::OnMoveLeftRight(float Value)
{
	PixelCharacter->MoveLeftRight(Value);
	//UE_LOG(LogTemp, Warning, TEXT("Press AD"))
}

void APixelCharacterPlayerController::OnMoveUpDown(float Value)
{
	PixelCharacter->MoveUpDown(Value);
}

void APixelCharacterPlayerController::OnJump()
{
	PixelCharacter->BeginJump();
}

void APixelCharacterPlayerController::OnStopJump()
{
	PixelCharacter->StopJump();
}

void APixelCharacterPlayerController::OnAttack()
{
	PixelCharacter->Attack();
}

void APixelCharacterPlayerController::OnInteract()
{
	PixelCharacter->Interact();
}