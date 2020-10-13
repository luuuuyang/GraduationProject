// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Patrol.h"
#include "AI/PixelAIController.h"
#include "AI/PaperAICharacter.h"

UBTTask_Patrol::UBTTask_Patrol()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Patrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	return EBTNodeResult::InProgress;
}

void UBTTask_Patrol::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	APaperAICharacter* AICharacter = Cast<APaperAICharacter>(OwnerComp.GetAIOwner()->GetPawn());

	AICharacter->AddMovementInput(AICharacter->GetActorForwardVector());
	UE_LOG(LogTemp, Warning, TEXT("Patrol"))
}
