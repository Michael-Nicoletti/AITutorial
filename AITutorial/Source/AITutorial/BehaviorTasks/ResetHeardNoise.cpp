// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "ResetHeardNoise.h"




EBTNodeResult::Type UResetHeardNoise::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Bool>(BlackboardKey.GetSelectedKeyID()) != false)
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(BlackboardKey.GetSelectedKeyID(), false);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
