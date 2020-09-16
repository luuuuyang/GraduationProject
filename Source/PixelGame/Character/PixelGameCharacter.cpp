// Copyright Epic Games, Inc. All Rights Reserved.

#include "PixelGameCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(SideScrollerCharacter, Log, All);

//////////////////////////////////////////////////////////////////////////
// APixelGameCharacter

APixelGameCharacter::APixelGameCharacter()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->bEnableCameraLag = true;
	
	// Create an orthographic camera (no perspective) and attach it to the boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bAutoActivate = true;

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bImpartBaseVelocityY = false;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, 1.0f, 0.0f));
	GetCharacterMovement()->SetPlaneConstraintOrigin(FVector(0.0f, 1.0f, 0.0f));

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	// Note: This can cause a little floating when going up inclines; you can choose the tradeoff between better
	// behavior on the edge of a ledge versus inclines by setting this to true or false
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;

	// Enable replication on the Sprite component so animations show up when networked
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;

	PixelCharacterMovemonetComponent = CreateDefaultSubobject<UPixelCharacterMovemonetComponent>(TEXT("PixelCharacterMovement"));
}

//////////////////////////////////////////////////////////////////////////
// Animation

void APixelGameCharacter::UpdateAnimation()
{
	switch (AnimationState)
	{
	case AnimationStateEnum::NONE:
		break;
	case AnimationStateEnum::IDLE:
		if (IsMoving)
		{
			AnimationState = AnimationStateEnum::RUN;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Run"))
		}
		if (IsJumping)
		{
			AnimationState = AnimationStateEnum::JUMP;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Jump"))
		}
		if (IsFalling)
		{
			AnimationState = AnimationStateEnum::FALL;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Fall"))
		}
		break;
	case AnimationStateEnum::RUN:
		if (!IsMoving)
		{
			AnimationState = AnimationStateEnum::IDLE;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Idle"))
		}
		if (IsJumping)
		{
			AnimationState = AnimationStateEnum::JUMP;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Jump"))
		}
		if (IsFalling)
		{
			AnimationState = AnimationStateEnum::FALL;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Fall"))
		}
		break;
	case AnimationStateEnum::JUMP:
		if (!IsJumping && !IsFalling)
		{
			AnimationState = AnimationStateEnum::IDLE;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Idle"))
		}
		if (IsFalling)
		{
			if (!GetWorldTimerManager().IsTimerActive(PlayFallingAnimationHandle))
			{
				GetWorldTimerManager().SetTimer(PlayFallingAnimationHandle, this, &APixelGameCharacter::PlayFallingAnimationDelegate, 0.2f, false);
			}
		}
		break;
	case AnimationStateEnum::FALL:
		if (!IsFalling)
		{
			AnimationState = AnimationStateEnum::IDLE;
			UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Idle"))
		}
		break;
	default:
		break;
	}

	UPaperFlipbook* DesiredAnimation = IdleAnimation;

	switch (AnimationState)
	{
	case AnimationStateEnum::NONE:
		break;
	case AnimationStateEnum::IDLE:
		DesiredAnimation = IdleAnimation;
		UE_LOG(LogTemp, Warning, TEXT("DesiredAnimation set Idle"))
		break;
	case AnimationStateEnum::RUN:
		DesiredAnimation = RunningAnimation;
		UE_LOG(LogTemp, Warning, TEXT("DesiredAnimation set Running"))
		break;
	case AnimationStateEnum::JUMP:
		DesiredAnimation = JumpingAnimation;
		UE_LOG(LogTemp, Warning, TEXT("DesiredAnimation set Jumping"))
		break;
	case AnimationStateEnum::FALL:
		DesiredAnimation = FallingAnimation;
		UE_LOG(LogTemp, Warning, TEXT("DesiredAnimation set Falling"))
		break;
	default:
		break;
	}

	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

void APixelGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateCharacter();
}


//////////////////////////////////////////////////////////////////////////
// Input

void APixelGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
}

void APixelGameCharacter::MoveLeftRight(float Value)
{
	PixelCharacterMovemonetComponent->MoveLeftRight(this, Value);
	
	if (CanTurn)
	{
		if (Value > 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));
		} 
		if (Value < 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0f, 180.0f, 0.0f));
		}
	}
}

void APixelGameCharacter::MoveUpDown(float Value)
{
	PixelCharacterMovemonetComponent->MoveUpDown(this, Value);
}

void APixelGameCharacter::BeginJump()
{
	PixelCharacterMovemonetComponent->Jump(this);
	if (IsJumping)
	{
		GetWorldTimerManager().SetTimer(EndJumpTimerHandle, this, &APixelGameCharacter::EndJumpDelegate, 0.1f, false);
	}
}

void APixelGameCharacter::StopJump()
{
	PixelCharacterMovemonetComponent->StopJump(this);
	StopJumping();
}

void APixelGameCharacter::UpdateCharacter()
{
	// Update animation to match the motion
	UpdateAnimation();
}


void APixelGameCharacter::EndJumpDelegate()
{
	SetIsJumping(false);
	SetIsFalling(true);
}

void APixelGameCharacter::PlayFallingAnimationDelegate()
{
	AnimationState = AnimationStateEnum::FALL;
	GetWorldTimerManager().ClearTimer(PlayFallingAnimationHandle);
	UE_LOG(LogTemp, Warning, TEXT("AniamtionState Set Fall"))
}