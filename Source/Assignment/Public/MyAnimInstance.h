// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UMyAnimInstance();
	virtual void NativeUpdateAnimation(float deltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, Category = "Pawn", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float mCurPawnSpeed;
};
