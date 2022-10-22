// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacterController.h"
#include "Components/TextBlock.h"
#include "PlayerCharacterState.h"
#include "Weapon.h"
#include "InvenWidget.h"

void UShopWidget::NativeConstruct()
{
	UInvenAndShopWidget::NativeConstruct();
	if (BuyBtn != nullptr)
	{
		BuyBtn->OnClicked.AddDynamic(this, &UShopWidget::BuyBtnClicked);
	}
}

void UShopWidget::SelectWeapon(AWeapon* weapon)
{
	mSelectedWeapon = weapon;
}

void UShopWidget::SetWeaponText(FString name, int32 attack, int32 price)
{
	UInvenAndShopWidget::SetWeaponText(name, attack);
	if (WeaponPrice != nullptr)
	{
		WeaponPrice->SetText(FText::FromString(FString::FromInt(price)));
	}
}

void UShopWidget::BuyBtnClicked()
{
	if (mSelectedWeapon == nullptr)
	{
		return;
	}

	if (mState->GetCurMoney() < mSelectedWeapon->GetWeaponPrice())
	{
		return;
	}

	if (mController->AddInven(mSelectedWeapon))
	{
		mState->SetMoney(mState->GetCurMoney() - mSelectedWeapon->GetWeaponPrice());
		UpdateCurMoney();
	}
}