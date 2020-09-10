// Copyright Epic Games, Inc. All Rights Reserved.

#include "PixelGameGameMode.h"
#include "PixelGameCharacter.h"

APixelGameGameMode::APixelGameGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = APixelGameCharacter::StaticClass();	
}
