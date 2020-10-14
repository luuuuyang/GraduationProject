// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "AI/PixelAIController.h"
#include "AI/PaperAICharacter.h"
#include "Components/CapsuleComponent.h"
#include "BTService_JudgePatrol.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API UBTService_JudgePatrol : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_JudgePatrol();

protected:
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	APaperAICharacter* AICharacter;

	float CapsuleRadius;
	float CapsuleHalfHeight;

	float ForwardTraceDistance;
	float DownwardTraceDistance;

	FName CanPatrol;
};
