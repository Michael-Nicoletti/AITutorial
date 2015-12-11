// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"
#include "AiCharacter.generated.h"

UCLASS()
class AITUTORIAL_API AAiCharacter : public ACharacter
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree;

public:
	AAiCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensingComponent;

	UPROPERTY(EditAnywhere)
	FName InvestigatePositionKeyName;
	UPROPERTY(EditAnywhere)
	FName HasHeardNoiseKeyName;

	UPROPERTY(EditAnywhere)
	FName EnemyActorKeyName;

protected:

	UFUNCTION()
	void OnSeePlayer(APawn* Pawn);

	UFUNCTION()
	void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);
};
