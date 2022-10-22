// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PlayerCharacter.h"
#include "EnemyAIController.h"
#include "DrawDebugHelpers.h"

UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory, float deltaSeconds)
{
	Super::TickNode(ownerComp, nodeMemory, deltaSeconds);

	APawn* pawn = ownerComp.GetAIOwner()->GetPawn();

	FCollisionQueryParams queryParams(NAME_None, false, pawn);
	TArray<FOverlapResult> overlapResults;
	bool result = GetWorld()->OverlapMultiByChannel(
		overlapResults,
		pawn->GetActorLocation(),
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(400.f),
		queryParams
	);

	if (result)
	{
		ownerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, nullptr);
		for (const auto& overlapResult : overlapResults)
		{
			APlayerCharacter* player = Cast<APlayerCharacter>(overlapResult.GetActor());
			if (player != nullptr && player->GetController()->IsPlayerController())
			{
				ownerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, player);
				DrawDebugSphere(GetWorld(), pawn->GetActorLocation(), 400.f, 16, FColor::Blue, false, 0.2f);
				return;
			}
		}
	}
	else
	{
		ownerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, nullptr);
	}

	DrawDebugSphere(GetWorld(), pawn->GetActorLocation(), 400.f, 16, FColor::Red, false, 0.2f);

}
