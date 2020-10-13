// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/AttackComponent.h"
#include "Components/HealthComponent.h"
#include "Components/WidgetComponent.h"
#include "Interfaces/GameplayTagInterface.h"
#include "BehaviorTree/BehaviorTree.h"
#include "PaperAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API APaperAICharacter : public APaperCharacter, public IGameplayTagInterface
{
	GENERATED_BODY()

public:
	APaperAICharacter();

	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnDeath();

	UFUNCTION()
	void OnHurt(int32 NewCurrentHealth);
	
	UFUNCTION()
	void Patrol();

	UFUNCTION()
	FORCEINLINE class UAttackComponent* GetAttackComponent() const { return AttackComponent; }

	UFUNCTION()
	FORCEINLINE class UHealthComponent* GetHealthComponent() const { return HealthComponent; }

	UFUNCTION()
	FORCEINLINE class UWidgetComponent* GetHealthWidgetComponent() const { return HealthWidgetComponent; }
public:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* AIBehaviorTree;

private:
	UPROPERTY()
	class UAttackComponent* AttackComponent;

	UPROPERTY(EditAnywhere)
	class UHealthComponent* HealthComponent;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* HealthWidgetComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTag")
	FGameplayTagContainer OwnedTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTag")
	FGameplayTagContainer EnemyTag;

	virtual FGameplayTagContainer GetOwnedTag() const override { return OwnedTag; }

	virtual FGameplayTagContainer GetEnemyTag() const override { return EnemyTag; }
};
