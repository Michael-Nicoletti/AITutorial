// Fill out your copyright notice in the Description page of Project Settings.

#include "AITutorial.h"
#include "MyAIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AiCharacter.h"


// Sets default values
AAiCharacter::AAiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AMyAIController::StaticClass();

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComponent"));

}

void AAiCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComponent)
	{
		PawnSensingComponent->OnSeePawn.AddDynamic(this, &AAiCharacter::OnSeePlayer);
		PawnSensingComponent->OnHearNoise.AddDynamic(this, &AAiCharacter::OnHearNoise);
	}
}

void AAiCharacter::OnSeePlayer(APawn* Pawn)
{
	GEngine->AddOnScreenDebugMessage(1, 0.2f, FColor::Red, TEXT("Can See Pawn"));

	float Dist = FVector::Dist(Pawn->GetActorLocation(), this->GetActorLocation());

	if (Dist < 900)
	{
		AMyAIController* Controller = Cast<AMyAIController>(GetController());

		if (Controller)
		{
			Controller->GetBlackBoardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyActorKeyName, Pawn);
		}
	}
}

void AAiCharacter::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume)
{
	float Dist = FVector::Dist(PawnInstigator->GetActorLocation(), Location);

	if (Dist < 900)
	{
		AMyAIController* Controller = Cast<AMyAIController>(GetController());

		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Red, TEXT("Can Hear Pawn"));

		if (Controller)
		{
			Controller->GetBlackBoardComponent()->SetValue<UBlackboardKeyType_Vector>(InvestigatePositionKeyName, Location);
			Controller->GetBlackBoardComponent()->SetValue<UBlackboardKeyType_Bool>(HasHeardNoiseKeyName, true);
		}
	}
}


