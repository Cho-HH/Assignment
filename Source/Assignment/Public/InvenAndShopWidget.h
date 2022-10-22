// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InvenAndShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UInvenAndShopWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateCurMoney();

protected:
	virtual void NativeConstruct() override;

	virtual void SetWeaponText(FString name, int32 attack);

	UPROPERTY(meta = (BindWidget))
		class UButton* BackBtn;

	UFUNCTION()
		void BakcBtnClicked();

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurMoneyText;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponName;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponAttack;

	class APlayerCharacterController* mController;
	class APlayerCharacterState* mState;

	class AWeapon* mSelectedWeapon;

};
