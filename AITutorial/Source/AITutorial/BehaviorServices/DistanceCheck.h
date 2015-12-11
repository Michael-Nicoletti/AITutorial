// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "DistanceCheck.generated.h"

/**
 * 
 */
UCLASS()
class AITUTORIAL_API UDistanceCheck : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	FName KeyName;

	UPROPERTY(EditAnywhere)
	FName TargetName;


protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	float Dist;
	
	
	
	
};
