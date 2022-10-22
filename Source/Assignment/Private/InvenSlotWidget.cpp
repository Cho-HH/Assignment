// Fill out your copyright notice in the Description page of Project Settings.


#include "InvenSlotWidget.h"
#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "InvenWidget.h"
#include "Weapon.h"
#include "Components/Button.h"

void UInvenSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (IconBtn != nullptr)
	{
		IconBtn->OnClicked.AddDynamic(this, &UInvenSlotWidget::SlotBtnClicked);
	}

	
	if (mInvenWidget == nullptr)
	{
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
		mInvenWidget = controller->GetInvenWidget();
	}
}

void UInvenSlotWidget::SlotBtnClicked()
{
	if (mWeapon == nullptr)
	{
		mInvenWidget->SetWeaponNameText(FText::FromString(FString::Printf(TEXT(""))));
		mInvenWidget->SetWeaponAttackText(0);
		mInvenWidget->SelectWeapon(nullptr, mSlotIndex);
		mInvenWidget->SetWeaponSellText(0);
	}
	else
	{
		mInvenWidget->SetWeaponNameText(FText::FromName(mWeapon->GetWeaponName()));
		mInvenWidget->SetWeaponAttackText(mWeapon->GetWeaponAttack());	
		mInvenWidget->SelectWeapon(mWeapon, mSlotIndex);
		mInvenWidget->SetWeaponSellText(mWeapon->GetWeaponSell());
	}
}

void UInvenSlotWidget::SetSlot(AWeapon* weapon)
{
	if (mInvenWidget == nullptr)
	{
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
		mInvenWidget = controller->GetInvenWidget();
	}
	mWeapon = weapon;
	mWeapon == nullptr ? mWeaponClass = nullptr : mWeaponClass = mWeapon->GetClass();	
}

class AWeapon* UInvenSlotWidget::GetWeapon() const
{
	return mWeapon;
}

int32 UInvenSlotWidget::GetSlotIndex() const
{
	return mSlotIndex;
}
