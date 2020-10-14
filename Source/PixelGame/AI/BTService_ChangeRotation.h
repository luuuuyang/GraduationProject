// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "AI/PixelAIController.h"
#include "BTService_ChangeRotation.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API UBTService_ChangeRotation : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_ChangeRotation();

protected:
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
