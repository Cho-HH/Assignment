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
	Super::NativeConstruct();
	mController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	mState = Cast<APlayerCharacterState>(mController->PlayerState);

	if (BackBtn != nullptr)
	{
		BackBtn->OnClicked.AddDynamic(this, &UInvenWidget::BakcBtnClicked);
	}

	if (EquipBtn != nullptr)
	{
		EquipBtn->OnClicked.AddDynamic(this, &UInvenWidget::EquipBtnClicked);
	}

	if (SellBtn != nullptr)
	{
		SellBtn->OnClicked.AddDynamic(this, &UInvenWidget::SellBtnClicked);
	}

	UpdateCurMoney();

	mSlots.Add(Slot_1);
	mSlots.Add(Slot_2);
	mSlots.Add(Slot_3);
	mSlots.Add(Slot_4);
	mSlots.Add(Slot_5);
	mSlots.Add(Slot_6);
}

void UInvenWidget::BakcBtnClicked()
{
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	controller->closeWidget(this);
}

void UInvenWidget::SellBtnClicked()
{
	if (mSlots[mSelectedSlotIndex]->GetWeapon() == nullptr)
	{
		return;
	}

	mState->SetMoney(mState->GetCurMoney() + mSlots[mSelectedSlotIndex]->GetWeapon()->GetWeaponSell());
	mSlots[mSelectedSlotIndex]->SetSlot(nullptr);
	UpdateCurMoney();
	UpdateWidgetImage();
}

void UInvenWidget::EquipBtnClicked()
{
	UpdateWidgetImage();
}

void UInvenWidget::UpdateCurMoney()
{
	if (CurMoneyText != nullptr)
	{
		CurMoneyText->SetText(FText::FromString(FString::FromInt(mState->GetCurMoney())));
	}
}

void UInvenWidget::SetWeaponNameText(FText name)
{
	if (WeaponName != nullptr)
	{
		WeaponName->SetText(name);
	}
}

void UInvenWidget::SetWeaponAttackText(int32 attack)
{
	if (WeaponAttack != nullptr)
	{
		WeaponAttack->SetText(FText::FromString(FString::FromInt(attack)));
	}
}

void UInvenWidget::SetWeaponSellText(int32 sellPrice)
{
	if (WeaponSell != nullptr)
	{
		WeaponSell->SetText(FText::FromString(FString::FromInt(sellPrice)));
	}
}

void UInvenWidget::SelectWeapon(AWeapon* weapon, int32 slotIndex)
{
	mSelectedWeapon = weapon;
	mSelectedSlotIndex = slotIndex;
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

	return false;
}
