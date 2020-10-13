// Fill out your copyright notice in the Description page of Project Settings.


#include "PixelAIController.h"
#include "AI/PaperAICharacter.h"

APixelAIController::APixelAIController(const FObjectInitializer& ObjectInitializer)
{
	BlackboardComponent = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));
	BehaviorTreeComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComponent"));
}

void APixelAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	APaperAICharacter* AICharacter = Cast<APaperAICharacter>(InPawn);
	if (AICharacter)
	{
		if (AICharacter->AIBehaviorTree)
		{
			if (AICharacter->AIBehaviorTree->BlackboardAsset)
			{
				BlackboardComponent->InitializeBlackboard(*AICharacter->AIBehaviorTree->BlackboardAsset);
				BehaviorTreeComponent->StartTree(*AICharacter->AIBehaviorTree);
			}
		}
	}
}

void APixelAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
