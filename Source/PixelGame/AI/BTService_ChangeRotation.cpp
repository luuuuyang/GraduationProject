// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_ChangeRotation.h"

UBTService_ChangeRotation::UBTService_ChangeRotation()
{
	bNotifyBecomeRelevant = true;
}

void UBTService_ChangeRotation::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FName FaceRotation("FaceRotation");
	FRotator Rotation = OwnerComp.GetAIOwner()->GetPawn()->GetActorRotation().Add(0.0f, 180.0f, 0.0f);
	OwnerComp.GetAIOwner()->GetBlackboardComponent()->SetValueAsRotator(FaceRotation, Rotation);
}
