// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/PixelCharacterMovemonetComponent.h"
#include "Animation/AnimInstance.h"
#include "PixelGameCharacter.generated.h"

class UTextRenderComponent;

UENUM(BlueprintType)
enum class AnimationStateEnum : uint8
{
	NONE UMETA(DisplayName = "None"),
	IDLE UMETA(DisplayName = "Idle"),
	RUN UMETA(DisplayName = "Run"),
	JUMP UMETA(DisplayName = "Jump"),
	FALL UMETA(DisplayName = "Fall")
};

/**
 * This class is the default character for PixelGame, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS(config=Game)
class APixelGameCharacter : public APaperCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UTextRenderComponent* TextComponent;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY()
	class UPixelCharacterMovemonetComponent* PixelCharacterMovemonetComponent;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enums)
	AnimationStateEnum AnimationState = AnimationStateEnum::NONE;

	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* JumpingAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* FallingAnimation;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	void UpdateCharacter();

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	APixelGameCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

// 函数接口
public:
	UFUNCTION()
	void MoveLeftRight(float Value);

	UFUNCTION()
	void MoveUpDown(float Value);

	UFUNCTION()
	void BeginJump();

	UFUNCTION()
	void StopJump();


//GetSet接口
public:
	FORCEINLINE void SetAnimationState(AnimationStateEnum Value) { AnimationState = Value; }
	FORCEINLINE AnimationStateEnum GetAnimationState() const { return AnimationState; }

	FORCEINLINE void SetIsMoving(bool Value) { IsMoving = Value; }
	FORCEINLINE bool GetIsMoving() const { return IsMoving; }

	FORCEINLINE void SetCanTurn(bool Value) { CanTurn = Value; }
	FORCEINLINE bool GetCanTurn() const { return CanTurn; }

	FORCEINLINE void SetPressUp(bool Value) { PressUp = Value; }
	FORCEINLINE bool GetPressUp() const { return PressUp; }

	FORCEINLINE void SetPressDown(bool Value) { PressDown = Value; }
	FORCEINLINE bool GetPressDown() const { return PressDown; }

	FORCEINLINE void SetIsJumping(bool Value) { IsJumping = Value; }
	FORCEINLINE bool GetIsJumping() const { return IsJumping; }

	FORCEINLINE void SetIsFalling(bool Value) { IsFalling = Value; }
	FORCEINLINE bool GetIsFalling() const { return IsFalling; }

// 变量
protected:
	UPROPERTY(BlueprintReadWrite)
	bool IsMoving;
	UPROPERTY(BlueprintReadWrite)
	bool CanTurn;
	UPROPERTY(BlueprintReadWrite)
	bool PressUp;
	UPROPERTY(BlueprintReadWrite)
	bool PressDown;
	UPROPERTY(BlueprintReadWrite)
	bool IsJumping;
	UPROPERTY(BlueprintReadWrite)
	bool IsFalling;

// 定时器句柄
protected:
	FTimerHandle EndJumpTimerHandle;
	FTimerHandle PlayFallingAnimationHandle;
// 定时器委托
protected:
	void EndJumpDelegate();
	void PlayFallingAnimationDelegate();
};