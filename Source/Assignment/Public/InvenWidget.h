// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InvenAndShopWidget.h"
#include "InvenWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UInvenWidget : public UInvenAndShopWidget
{
	GENERATED_BODY()
	
public:	
	void UpdateWidgetImage();
	bool AddInven(class AWeapon* weapon);
	void SelectWeapon(class AWeapon* weapon, int32 slotIndex);
	void SetWeaponText(FString name, int32 attack, int32 sellPrice);

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* EquipBtn;

	UFUNCTION()
		void EquipBtnClicked();

	UPROPERTY(meta = (BindWidget))
		class UButton* SellBtn;

	UFUNCTION()
		void SellBtnClicked();

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponSell;

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

	TArray<class UInvenSlotWidget*> mSlots;

	int32 mSelectedSlotIndex;

};
