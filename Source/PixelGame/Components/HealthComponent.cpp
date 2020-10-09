// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentHealth = 100;
	MaxHealth = 100;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//DecreaseCurrentHealth(1);
}

void UHealthComponent::IncreaseCurrentHealth(int32 IncreaseValue)
{

}

void UHealthComponent::DecreaseCurrentHealth(int32 DecreaseValue)
{
	CurrentHealth -= DecreaseValue;
	UE_LOG(LogTemp, Warning, TEXT("%d"), CurrentHealth)
	if (OnCurrentHealthChanged.IsBound())
	{
		UE_LOG(LogTemp, Warning, TEXT("before %d"), CurrentHealth)
		OnCurrentHealthChanged.Execute(CurrentHealth);
		UE_LOG(LogTemp, Warning, TEXT("OnHealthChanged"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnHealthChanged Empty"))
	}
}

void UHealthComponent::IncreaseMaxHealth(int32 IncreaseValue)
{

}

void UHealthComponent::DecreaseMaxHealth(int32 DecreaseValue)
{

}

