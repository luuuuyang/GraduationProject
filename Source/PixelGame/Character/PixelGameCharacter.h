// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/PixelCharacterMovemonetComponent.h"
#include "PixelGameCharacter.generated.h"

class UTextRenderComponent;

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
	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	void UpdateCharacter();

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	APixelGameCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

// 公共接口
public:
	UFUNCTION()
	void MoveLeftRight(float Value);

	UFUNCTION()
	void MoveUpDown(float Value);

//GetSet接口
public:
	FORCEINLINE void SetIsMoving(bool Value) { IsMoving = Value; }
	FORCEINLINE bool GetIsMoving() const { return IsMoving; }
	FORCEINLINE void SetCanTurn(bool Value) { CanTurn = Value; }
	FORCEINLINE bool GetCanTurn() const { return CanTurn; }
	FORCEINLINE void SetPressUp(bool Value) { PressUp = Value; }
	FORCEINLINE bool GetPressUp() const { return PressUp; }
	FORCEINLINE void SetPressDown(bool Value) { PressDown = Value; }
	FORCEINLINE bool GetPressDown() const { return PressDown; }

// 变量
protected:
	UPROPERTY()
	bool IsMoving;
	UPROPERTY()
	bool CanTurn;
	UPROPERTY()
	bool PressUp;
	UPROPERTY()
	bool PressDown;
};
