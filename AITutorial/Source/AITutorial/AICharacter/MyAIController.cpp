// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "AiCharacter.h"
#include "MyAIController.h"

AMyAIController::AMyAIController()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AMyAIController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	AAiCharacter* Character = Cast<AAiCharacter>(Pawn);

	if (Character && Character->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*Character->BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*Character->BehaviorTree);
	}
}

UBlackboardComponent* AMyAIController::GetBlackBoardComponent()
{
	return BlackboardComponent;
}





