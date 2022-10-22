// Fill out your copyright notice in the Description page of Project Settings.


#include "InvenWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacterController.h"
#include "Components/TextBlock.h"
#include "Weapon.h"
#include "PlayerCharacterState.h"
#include "InvenSlotWidget.h"

void UInvenWidget::NativeConstruct()
{
	UInvenAndShopWidget::NativeConstruct();

	if (EquipBtn != nullptr)
	{
		EquipBtn->OnClicked.AddDynamic(this, &UInvenWidget::EquipBtnClicked);
	}

	if (SellBtn != nullptr)
	{
		SellBtn->OnClicked.AddDynamic(this, &UInvenWidget::SellBtnClicked);
	}

	mSlots.Add(Slot_1);
	mSlots.Add(Slot_2);
	mSlots.Add(Slot_3);
	mSlots.Add(Slot_4);
	mSlots.Add(Slot_5);
	mSlots.Add(Slot_6);
}

void UInvenWidget::SellBtnClicked()
{
	if (mSlots[mSelectedSlotIndex]->GetWeapon() == nullptr)
	{
		return;
	}

	mState->SetMoney(mState->GetCurMoney() + mSlots[mSelectedSlotIndex]->GetWeapon()->GetWeaponSell());
	mSlots[mSelectedSlotIndex]->SetSlot(nullptr);
	SetWeaponText(TEXT(""), 0, 0);
	UpdateCurMoney();
	UpdateWidgetImage();
}

void UInvenWidget::EquipBtnClicked()
{
	if (mSlots[mSelectedSlotIndex]->GetWeapon() == nullptr)
	{
		return;
	}

	mController->ChangeWeapon(mSelectedWeapon->GetClass());
	mSlots[mSelectedSlotIndex]->SetSlot(nullptr);
	SetWeaponText(TEXT(""), 0, 0);
	UpdateWidgetImage();
}

void UInvenWidget::SelectWeapon(AWeapon* weapon, int32 slotIndex)
{
	mSelectedWeapon = weapon;
	mSelectedSlotIndex = slotIndex;
}

void UInvenWidget::SetWeaponText(FString name, int32 attack, int32 sellPrice)
{
	UInvenAndShopWidget::SetWeaponText(name, attack);
	if (WeaponSell != nullptr)
	{
		WeaponSell->SetText(FText::FromString(FString::FromInt(sellPrice)));
	}
}

void UInvenWidget::UpdateWidgetImage()
{
	for (int i = 0; i < mSlots.Num(); i++)
	{
		mSlots[i]->UpdateWidgetIcon();
	}
}

bool UInvenWidget::AddInven(AWeapon* weapon)
{
	for (int i = 0; i < mSlots.Num(); i++)
	{
		if (mSlots[i]->GetWeapon() == nullptr)
		{
			mSlots[i]->SetSlot(weapon);
			return true;
			break;
		}
	}

	UpdateWidgetImage();
	return false;
}
