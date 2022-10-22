// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AEnemyAIController::HomePosKey(TEXT("HomePos"));
const FName AEnemyAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AEnemyAIController::TargetKey(TEXT("Player"));

AEnemyAIController::AEnemyAIController()
{
}

void AEnemyAIController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);
	if (UseBlackboard(mBBoard, (UBlackboardComponent*)Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, pawn->GetActorLocation());
		RunBehaviorTree(mBTree);
	}
}
