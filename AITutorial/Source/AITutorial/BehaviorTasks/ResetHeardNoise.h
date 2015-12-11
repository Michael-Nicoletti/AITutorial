// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "ResetHeardNoise.generated.h"

/**
 * 
 */
UCLASS()
class AITUTORIAL_API UResetHeardNoise : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	
	bool ToResetTo;
	
	
};
