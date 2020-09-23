// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PIXELGAME_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY()
	bool bIsAttacking;

public:
	FORCEINLINE void SetIsAttacking(bool Value) { bIsAttacking = Value; }
	FORCEINLINE bool GetIsAttacking() const { return bIsAttacking; }

protected:
	UPROPERTY()
	TArray<FName> SocketName;

	UPROPERTY()
	TArray<AActor*> ActorsToIgnore;

	UPROPERTY()
	FVector PreLocation;
		
};
