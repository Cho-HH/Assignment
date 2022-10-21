// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerCharacterState.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API APlayerCharacterState : public APlayerState
{
	GENERATED_BODY()
	
public:
	APlayerCharacterState();
	void SetName(const FString& name);

	int32 GetCurMoney() const;
	void SetMoney(int32 money);

	int32 GetMaxHP() const;
	int32 GetCurHP() const;
	int32 SetCurHP(int32 hp);

private:
	int32 mCurMoney;

	int32 mMaxHP;
	int32 mCurHP;

	TArray<class AActor> mInventory;
};
