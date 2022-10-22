// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"

UMyAnimInstance::UMyAnimInstance()
	: mCurPawnSpeed(0.f)
{
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
