// Copyright Epic Games, Inc. All Rights Reserved.

#include "PixelGameGameMode.h"
#include "Character/PixelGameCharacter.h"
#include "PlayerController/PixelCharacterPlayerController.h"

APixelGameGameMode::APixelGameGameMode()
{
	//设置默认Pawn类 = APixelGameCharacter
	DefaultPawnClass = APixelGameCharacter::StaticClass();
	//设置默认PlayerController类 = APixelCharacterPlayerController
	PlayerControllerClass = APixelCharacterPlayerController::StaticClass();
}
