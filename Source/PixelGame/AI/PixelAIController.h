// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PixelAIController.generated.h"

/**
 * 
 */
UCLASS()
class PIXELGAME_API APixelAIController : public AAIController
{
	GENERATED_BODY()

public:
	APixelAIController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
public:
	UPROPERTY(transient)
	UBlackboardComponent* BlackboardComponent;
	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorTreeComponent;

};
