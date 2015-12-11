// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "ResetTargetTask.h"

EBTNodeResult::Type UResetTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(ResetActorKeyName) != NULL)
	{
		AActor* EmptyActor = NULL;

		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(ResetActorKeyName, EmptyActor);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

EBTNodeResult::Type UResetTargetTask::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::AbortTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(ResetActorKeyName) != NULL)
	{
		AActor* EmptyActor = NULL;

		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(ResetActorKeyName, EmptyActor);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

