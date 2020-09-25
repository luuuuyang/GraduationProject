// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "Character/PixelGameCharacter.h"
#include "Items/PickupItem.h"
#include "Engine/EngineTypes.h"
#include "DrawDebugHelpers.h"


// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsAttacking)
	{
		UPaperFlipbookComponent* Character = Cast<APixelGameCharacter>(GetOwner())->GetSprite();

		HitSocketName = Character->GetAllSocketNames();
		
		
		if (DoOnce)
		{
			StartLocation = Character->GetSocketLocation(FName("Self"));
			ActorsToIgnore.Empty();
			DoOnce = false;
		}

		TArray<FHitResult> HitResults;
		
		for (auto SocketName : HitSocketName)
		{
			EndLocation = Character->GetSocketLocation(SocketName);

																//Warning 直接访问数组内存
			FCollisionShape CollisionShape = FCollisionShape::MakeSphere(MeleeWeapon[0].AttackRadius);

			FCollisionQueryParams CollisionQueryParams;
			CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);

			if (GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::Identity, ECollisionChannel::ECC_Camera, CollisionShape, CollisionQueryParams))
			{
				for (auto Hit : HitResults)
				{
					UE_LOG(LogTemp, Warning, TEXT("Hit Success, %s"), *Hit.Actor->GetName())
				}
			}

			
			
			StartLocation = EndLocation;

			for (auto Hit : HitResults)
			{
				ActorsToIgnore.AddUnique(Hit.Actor.Get());
			}
		}

	}
	else
	{
		DoOnce = true;
	}
}

void UAttackComponent::SetMeleeWeaponProperty(FMeleeWeaponProperty MeleeWeaponProperty)
{
	MeleeWeapon.Emplace(MeleeWeaponProperty);
}
