// Copyright Epic Games, Inc. All Rights Reserved.

#include "PixelGameGameMode.h"
#include "Character/PixelGameCharacter.h"
#include "PlayerController/PixelCharacterPlayerController.h"

APixelGameGameMode::APixelGameGameMode()
{
	//����Ĭ��Pawn�� = APixelGameCharacter
	DefaultPawnClass = APixelGameCharacter::StaticClass();
	//����Ĭ��PlayerController�� = APixelCharacterPlayerController
	PlayerControllerClass = APixelCharacterPlayerController::StaticClass();
}
