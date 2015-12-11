// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "AITutorialCharacter.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "FindPlayerTask.h"

EBTNodeResult::Type UFindPlayerTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	for (TActorIterator<AAITutorialCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AAITutorialCharacter* PlayerCharacter = *ActorItr;
		if (PlayerCharacter)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), PlayerCharacter);

			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}




