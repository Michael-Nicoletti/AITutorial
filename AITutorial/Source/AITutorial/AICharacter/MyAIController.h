// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class AITUTORIAL_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMyAIController();

	UBlackboardComponent* GetBlackBoardComponent();

	virtual void Possess(APawn* Pawn) override;

protected:
	UPROPERTY(VisibleAnywhere)
	UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere)
	UBlackboardComponent* BlackboardComponent;
	
};
