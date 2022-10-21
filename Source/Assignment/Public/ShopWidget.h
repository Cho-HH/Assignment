// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetWeaponNameText(FText name);
	void SetWeaponPriceText(int32 price);
	void SetWeaponAttackText(int32 attack);

	void SelectWeapon(class AWeapon* weapon);

protected:
	virtual void NativeConstruct() override;

private:
	void UpdateCurMoney();

	UPROPERTY(meta = (BindWidget))
		class UButton* BackBtn;

	UFUNCTION()
		void BakcBtnClicked();

	UPROPERTY(meta = (BindWidget))
		class UButton* BuyBtn;

	UFUNCTION()
		void BuyBtnClicked();

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurMoneyText;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponName;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponPrice;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponAttack;

	class APlayerCharacterController* mController;
	class APlayerCharacterState* mState;

	class AWeapon* mSelectedWeapon;
};
