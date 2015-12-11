// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FindGuardPost.h"


EBTNodeResult::Type UFindGuardPost::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	for (TActorIterator<ATargetPoint> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ATargetPoint* GuardPost = *ActorItr;
		if (GuardPost)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), GuardPost);

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}

