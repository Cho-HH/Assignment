// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InvenWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UInvenWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateCurMoney();

	void SetWeaponNameText(FText name);
	void SetWeaponAttackText(int32 attack);
	void SelectWeapon(class AWeapon* weapon);

	void UpdateWidgetImage();
	bool AddInven(class AWeapon* weapon);

protected:
	virtual void NativeConstruct() override;

private:
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

	UPROPERTY(meta = (BindWidget))
		class UButton* EquipBtn;

	UPROPERTY(meta = (BindWidget))
		class UInvenSlotWidget* Slot_1;

	UPROPERTY(meta = (BindWidget))
		class UInvenSlotWidget* Slot_2;

	UPROPERTY(meta = (BindWidget))
		class UInvenSlotWidget* Slot_3;

	UPROPERTY(meta = (BindWidget))
		class UInvenSlotWidget* Slot_4;

	UPROPERTY(meta = (BindWidget))
		class UInvenSlotWidget* Slot_5;

	UPROPERTY(meta = (BindWidget))
		class UInvenSlotWidget* Slot_6;

	UFUNCTION()
		void EquipBtnClicked();

	class APlayerCharacterController* mController;
	class APlayerCharacterState* mState;

	class AWeapon* mSelectedWeapon;

	int32 mCurAddIndex;
};
