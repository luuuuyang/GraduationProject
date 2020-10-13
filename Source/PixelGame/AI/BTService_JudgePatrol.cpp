// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_JudgePatrol.h"
#include "Components/CapsuleComponent.h"
#include "DrawDebugHelpers.h"

UBTService_JudgePatrol::UBTService_JudgePatrol()
{
	bNotifyBecomeRelevant = true;
}

void UBTService_JudgePatrol::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);

	AICharacter = Cast<APaperAICharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AICharacter->GetCapsuleComponent()->GetUnscaledCapsuleSize(ForwardTraceDistance, DownwardTraceDistance);

	OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetKeyName(0), true);

}

void UBTService_JudgePatrol::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	FHitResult HitResult;
	FVector Start = AICharacter->GetActorLocation();
	FVector End = Start + AICharacter->GetActorForwardVector() * ForwardTraceDistance * 3.5f;

	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, true);
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(AICharacter);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, CollisionQueryParams))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *HitResult.Actor->GetName())
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetKeyName(0), false);
		FRotator FaceRotation = AICharacter->GetActorRotation().Add(0.0f, 180.0f, 0.0f);
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsRotator(OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetKeyName(1), FaceRotation);
	}
	else
	{
		OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsBool(OwnerComp.GetAIOwner()->GetBlackboardComponent()->GetKeyName(0), true);
		UE_LOG(LogTemp, Warning, TEXT("Not Hit"))
	}
}
