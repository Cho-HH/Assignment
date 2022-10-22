// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_TurnToTarget.h"
#include "PlayerCharacter.h"
#include "Enemy.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTaskNode_TurnToTarget::UBTTaskNode_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UBTTaskNode_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	EBTNodeResult::Type result = UBTTaskNode::ExecuteTask(ownerComp, nodeMemory);

	AEnemy* enemy = Cast<AEnemy>(ownerComp.GetAIOwner()->GetPawn());
	if (enemy->IsAlive())
	{
		APlayerCharacter* player = Cast<APlayerCharacter>(ownerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey));

		FVector lookVector = player->GetActorLocation() - enemy->GetActorLocation();
		FRotator targetRot = FRotationMatrix::MakeFromX(lookVector).Rotator();
		enemy->SetActorRotation(FMath::RInterpTo(enemy->GetActorRotation(), targetRot, GetWorld()->GetDeltaSeconds(), 2.f));
	}
	return EBTNodeResult::Succeeded;
}
