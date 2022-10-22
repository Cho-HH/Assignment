// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_Attack.h"
#include "EnemyAIController.h"
#include "Enemy.h"

UBTTaskNode_Attack::UBTTaskNode_Attack()
{
	//FinishLatenTask를 호출하기위해 켜줘야함
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTaskNode_Attack::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	EBTNodeResult::Type result = Super::ExecuteTask(ownerComp, nodeMemory);

	AEnemy* enemy = Cast<AEnemy>(ownerComp.GetAIOwner()->GetPawn());
	if (enemy == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	enemy->Attack();
	IsAttacking = true;
	enemy->OnAttackEnd.AddLambda([this]() {
		IsAttacking = false;
		});

	return EBTNodeResult::InProgress;
}

void UBTTaskNode_Attack::TickTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickTask(ownerComp, nodeMemory, deltaSeconds);
	if (IsAttacking == false)
	{
		FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);		
	}	
}
