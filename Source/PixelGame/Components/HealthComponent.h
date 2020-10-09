// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Widgets/HealthWidget.h"
#include "HealthComponent.generated.h"

DECLARE_DELEGATE_OneParam(FOnCurrentHealthChanged, int32)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXELGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FOnCurrentHealthChanged OnCurrentHealthChanged;

public:
	UFUNCTION()
	void IncreaseCurrentHealth(int32 IncreaseValue);

	UFUNCTION()
	void DecreaseCurrentHealth(int32 DecreaseValue);

	UFUNCTION()
	void IncreaseMaxHealth(int32 IncreaseValue);

	UFUNCTION()
	void DecreaseMaxHealth(int32 DecreaseValue);

public:
	FORCEINLINE void SetCurrentHealth(int32 Value) { CurrentHealth = Value; }
	FORCEINLINE int32 GetCurrentHealth() const { return CurrentHealth; }

	FORCEINLINE void SetMaxHealth(int32 Value) { MaxHealth = Value; }
	FORCEINLINE int32 GetMaxHealth() const { return MaxHealth; }

private:
	UPROPERTY()
	class UHealthWidget* HealthWidget;

public:
	UPROPERTY(EditAnywhere)
	int32 CurrentHealth;

	UPROPERTY(EditAnywhere)
	int32 MaxHealth;
};
