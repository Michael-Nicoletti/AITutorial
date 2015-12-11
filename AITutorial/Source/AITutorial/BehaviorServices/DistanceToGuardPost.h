// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "DistanceToGuardPost.generated.h"

/**
 * 
 */
UCLASS()
class AITUTORIAL_API UDistanceToGuardPost : public UBTService_BlackboardBase
{
	GENERATED_BODY()

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	float Dist;
	
	
	
	
};
