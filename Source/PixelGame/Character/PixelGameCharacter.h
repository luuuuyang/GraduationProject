// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/AttackComponent.h"
#include "Components/EquipmentComponent.h"
#include "Interfaces/ItemInteractionInterface.h"
#include "PixelGameCharacter.generated.h"

class UTextRenderComponent;

UENUM(BlueprintType)
enum class AnimationStateEnum : uint8
{
	NONE UMETA(DisplayName = "None"),
	IDLE UMETA(DisplayName = "Idle"),
	RUN UMETA(DisplayName = "Run"),
	JUMP UMETA(DisplayName = "Jump"),
	FALL UMETA(DisplayName = "Fall"),
	ATTACK UMETA(DisplayName = "Attack"),
	ATTACKRUN UMETA(DisplayName = "AttackRun")
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
	class UAttackComponent* AttackComponent;

	UPROPERTY()
	class UEquipmentComponent* EquipmentComponent;
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
	class UPaperFlipbook* JumpAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* FallAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackRunAnimation;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	void UpdateCharacter();

public:
	APixelGameCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UEquipmentComponent* GetEquipmentComponent() const { return EquipmentComponent; }

	FORCEINLINE class UAttackComponent* GetAttackComponent() const { return AttackComponent; }

// 函数接口
public:
	void MoveLeftRight(float Value);

	void MoveUpDown(float Value);

	void BeginJump();

	void EndJump();

	virtual void Landed(const FHitResult& Hit) override;

	void Attack_1();

	void Attack_2();

	void Interact();

//GetSet接口
public:
	FORCEINLINE void SetAnimationState(AnimationStateEnum Value) { AnimationState = Value; }
	FORCEINLINE AnimationStateEnum GetAnimationState() const { return AnimationState; }

	FORCEINLINE void SetIsMoving(bool Value) { bIsMoving = Value; }
	FORCEINLINE bool GetIsMoving() const { return bIsMoving; }

	FORCEINLINE void SetCanTurn(bool Value) { bCanTurn = Value; }
	FORCEINLINE bool GetCanTurn() const { return bCanTurn; }

	FORCEINLINE void SetPressUp(bool Value) { bPressUp = Value; }
	FORCEINLINE bool GetPressUp() const { return bPressUp; }

	FORCEINLINE void SetPressDown(bool Value) { bPressDown = Value; }
	FORCEINLINE bool GetPressDown() const { return bPressDown; }

	FORCEINLINE void SetIsJumping(bool Value) { bIsJumping = Value; }
	FORCEINLINE bool GetIsJumping() const { return bIsJumping; }

	FORCEINLINE void SetIsFalling(bool Value) { bIsFalling = Value; }
	FORCEINLINE bool GetIsFalling() const { return bIsFalling; }

	FORCEINLINE void SetIsAttacking(bool Value) { bIsAttacking = Value; }
	FORCEINLINE bool GetIsAttacking() const { return bIsAttacking; }

// 变量
protected:
	UPROPERTY(BlueprintReadWrite)
	bool bIsMoving;
	UPROPERTY(BlueprintReadWrite)
	bool bCanTurn;
	UPROPERTY(BlueprintReadWrite)
	bool bPressUp;
	UPROPERTY(BlueprintReadWrite)
	bool bPressDown;
	UPROPERTY(BlueprintReadWrite)
	bool bIsJumping;
	UPROPERTY(BlueprintReadWrite)
	bool bIsFalling;
	UPROPERTY(BlueprintReadWrite)
	bool bIsAttacking;


// 定时器句柄
protected:
	FTimerHandle EndJumpTimerHandle;
	FTimerHandle PlayFallingAnimationHandle;
	FTimerHandle EndAttackTimerHandle;
// 定时器委托
protected:
	void EndJumpDelegate();
	void PlayFallingAnimationDelegate();
	void EndAttackDelegate();
};
