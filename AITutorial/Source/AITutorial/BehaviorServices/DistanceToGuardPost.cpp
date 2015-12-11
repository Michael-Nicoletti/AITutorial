// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AICharacter/MyAIController.h"
#include "DistanceToGuardPost.h"

void UDistanceToGuardPost::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* Blackboard = Blackboard = OwnerComp.GetBlackboardComponent();

	uint8 TargetKeyID = Blackboard->GetKeyID("Target");

	UObject* TargetObject = Blackboard->GetValue<UBlackboardKeyType_Object>(TargetKeyID);

	AActor* TargetActor = Cast<AActor>(TargetObject);

	AMyAIController* AiController = Cast<AMyAIController>(Blackboard->GetOwner());

	if (AiController)
	{
		Dist = FVector::Dist(TargetActor->GetActorLocation(), AiController->GetPawn()->GetActorLocation());

		//Blackboard->SetValueAsFloat(TargetName, Dist);
	}
}


