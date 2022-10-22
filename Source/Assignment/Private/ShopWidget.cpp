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
	Super::NativeConstruct();
	mController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	mState = Cast<APlayerCharacterState>(mController->PlayerState);

	if (BackBtn != nullptr)
	{
		BackBtn->OnClicked.AddDynamic(this, &UShopWidget::BakcBtnClicked);
	}

	if (BuyBtn != nullptr)
	{
		BuyBtn->OnClicked.AddDynamic(this, &UShopWidget::BuyBtnClicked);
	}

	UpdateCurMoney();
}

void UShopWidget::UpdateCurMoney()
{
	if (CurMoneyText != nullptr)
	{
		CurMoneyText->SetText(FText::FromString(FString::FromInt(mState->GetCurMoney())));
	}
}

void UShopWidget::BakcBtnClicked()
{
	mController->closeWidget(this);
}

void UShopWidget::SetWeaponNameText(FText name)
{
	if (WeaponName != nullptr)
	{
		WeaponName->SetText(name);
	}
}

void UShopWidget::SetWeaponPriceText(int32 price)
{
	if (WeaponPrice != nullptr)
	{
		WeaponPrice->SetText(FText::FromString(FString::FromInt(price)));
	}
}

void UShopWidget::SetWeaponAttackText(int32 attack)
{
	if (WeaponAttack != nullptr)
	{
		WeaponAttack->SetText(FText::FromString(FString::FromInt(attack)));
	}
}

void UShopWidget::SelectWeapon(AWeapon* weapon)
{
	mSelectedWeapon = weapon;
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