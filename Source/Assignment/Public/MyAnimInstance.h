// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnAttackHitCheckDelegate);

UCLASS()
class ASSIGNMENT_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMyAnimInstance();
	virtual void NativeUpdateAnimation(float deltaSeconds) override;

	void PlayAttack();
	FOnAttackHitCheckDelegate OnAttackHitCheck;

	void SetDeadAnim();

private:
	UPROPERTY(EditAnywhere, Category = "Pawn", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float mCurPawnSpeed;

	UPROPERTY(VisibleDefaultsOnly, Category = "Attack", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* mAttackMontage;

	UFUNCTION()
		void AnimNotify_AttackHitCheck();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
		bool isDead;
};
