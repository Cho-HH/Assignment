// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInAttackRange.h"
#include "EnemyAIController.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) const
{
	bool result = Super::CalculateRawConditionValue(ownerComp, nodeMemory);

	APawn* pawn = ownerComp.GetAIOwner()->GetPawn();

	APlayerCharacter* target = Cast<APlayerCharacter>(ownerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey));
	if (target == nullptr)
	{
		return false;
	}

	result = (target->GetDistanceTo(pawn) <= 200.f);
	return result;
}
