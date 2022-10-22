// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPatrolPos.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTTask_FindPatrolPos::UBTTask_FindPatrolPos()
{
	NodeName = TEXT("FindPatrolPos");
}

EBTNodeResult::Type UBTTask_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(ownerComp, nodeMemory);

	APawn* pawn = ownerComp.GetAIOwner()->GetPawn();
	if (pawn == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	UNavigationSystemV1* navSys = UNavigationSystemV1::GetNavigationSystem(this);
	FNavLocation nextPatrol;

	if (navSys == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	FVector origin = ownerComp.GetBlackboardComponent()->GetValueAsVector(AEnemyAIController::HomePosKey);
	if (navSys->GetRandomPointInNavigableRadius(origin, 500.f, nextPatrol))
	{
		ownerComp.GetBlackboardComponent()->SetValueAsVector(AEnemyAIController::PatrolPosKey, nextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
