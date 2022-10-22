// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterState.h"

APlayerCharacterState::APlayerCharacterState()
	: mCurMoney(7000)
	, mMaxHP(500)
	, mCurHP(500)
	, mCurAttack(0)
{
}

void APlayerCharacterState::SetName(const FString& name)
{
	SetPlayerName(name);
}

int32 APlayerCharacterState::GetCurMoney() const
{
	return mCurMoney;
}

void APlayerCharacterState::SetMoney(int32 money)
{
	mCurMoney = money;
}

int32 APlayerCharacterState::GetMaxHP() const
{
	return mMaxHP;
}

int32 APlayerCharacterState::GetCurHP() const
{
	return mCurHP;
}

int32 APlayerCharacterState::SetCurHP(int32 hp)
{
	return mCurHP -= hp;
}

int32 APlayerCharacterState::GetAttack() const
{
	return mCurAttack;
}

void APlayerCharacterState::SetAttack(int32 attack)
{
	mCurAttack = attack;
}
