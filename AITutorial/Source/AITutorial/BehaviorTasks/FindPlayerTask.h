// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FindPlayerTask.generated.h"

/**
 * 
 */
UCLASS()
class AITUTORIAL_API UFindPlayerTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

protected:
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	
	
	
};
