// Fill out your copyright notice in the Description page of Project Settings.

#include "PixelCharacterMovemonetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values for this component's properties
UPixelCharacterMovemonetComponent::UPixelCharacterMovemonetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPixelCharacterMovemonetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPixelCharacterMovemonetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPixelCharacterMovemonetComponent::MoveLeftRight(APixelGameCharacter* PixelCharacter, float Value)
{
	if (Value != 0.0f)
	{
		PixelCharacter->SetIsMoving(true);
		PixelCharacter->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
	}
	else
	{
		PixelCharacter->SetIsMoving(false);
	}

	PixelCharacter->SetCanTurn(true);
}

void UPixelCharacterMovemonetComponent::MoveUpDown(APixelGameCharacter* PixelCharacter, float Value)
{
	if (Value > 0.0f)
	{
		PixelCharacter->SetPressUp(true);
		PixelCharacter->SetPressDown(false);
	} 
	else if (Value < 0.0f)
	{
		PixelCharacter->SetPressUp(false);
		PixelCharacter->SetPressDown(true);
	}
	else
	{
		PixelCharacter->SetPressUp(false);
		PixelCharacter->SetPressDown(false);
	}
}

void UPixelCharacterMovemonetComponent::Jump(APixelGameCharacter* PixelCharacter)
{
	if (!PixelCharacter->CanJump() && PixelCharacter->GetCharacterMovement()->IsFalling())
	{
		PixelCharacter->SetIsJumping(false);
	}
	else
	{
		PixelCharacter->SetIsJumping(true);
		PixelCharacter->Jump();
	}
}

void UPixelCharacterMovemonetComponent::StopJump(APixelGameCharacter* PixelCharacter)
{

}