// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_JudgePatrol.h"

#include "DrawDebugHelpers.h"

UBTService_JudgePatrol::UBTService_JudgePatrol()
{
	bNotifyBecomeRelevant = true;

	ForwardTraceDistance = 20.0f;
	DownwardTraceDistance = 20.0f;
	CanPatrol = FName("CanPatrol");
}

void UBTService_JudgePatrol::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	AICharacter = Cast<APaperAICharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AICharacter->GetCapsuleComponent()->GetUnscaledCapsuleSize(CapsuleRadius, CapsuleHalfHeight);

	OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(CanPatrol, true);
}

void UBTService_JudgePatrol::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	FHitResult ForwardTraceHitResult;
	FVector ForwardTraceStart = AICharacter->GetActorLocation();;
	FVector ForwardTraceEnd = ForwardTraceStart + AICharacter->GetActorForwardVector() * (CapsuleRadius + ForwardTraceDistance);

	FHitResult DownwardTraceHitResult;
	FVector DownwardTraceStart = ForwardTraceEnd;
	FVector DownwardTraceEnd = DownwardTraceStart + AICharacter->GetActorUpVector() * -(CapsuleHalfHeight + DownwardTraceDistance);

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(AICharacter);

	if (GetWorld()->LineTraceSingleByChannel(ForwardTraceHitResult, ForwardTraceStart, ForwardTraceEnd, ECollisionChannel::ECC_Visibility, CollisionQueryParams) ||
	    !GetWorld()->LineTraceSingleByChannel(DownwardTraceHitResult, DownwardTraceStart, DownwardTraceEnd, ECollisionChannel::ECC_Visibility, CollisionQueryParams))
	{
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(CanPatrol, false);
	}
	else
	{
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(CanPatrol, true);
	}
}
