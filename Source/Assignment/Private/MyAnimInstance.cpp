// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

UMyAnimInstance::UMyAnimInstance()
	: mCurPawnSpeed(0.f)
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> montage(TEXT("/Game/Animation/SK_Mannequin_Skeleton_Montage.SK_Mannequin_Skeleton_Montage"));
	if (montage.Succeeded())
	{
		mAttackMontage = montage.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float deltaSeconds)
{
	Super::NativeUpdateAnimation(deltaSeconds);

	APawn* pawn = TryGetPawnOwner();
	if (pawn != nullptr)
	{
		mCurPawnSpeed = pawn->GetVelocity().Size();
	}
}

void UMyAnimInstance::PlayAttack()
{
	if (!Montage_IsPlaying(mAttackMontage))
	{
		Montage_Play(mAttackMontage, 1.f);
	}
}

void UMyAnimInstance::SetDeadAnim()
{
	isDead = true;
}

void UMyAnimInstance::AnimNotify_AttackHitCheck()
{
	OnAttackHitCheck.Broadcast();
}
