// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopSlotWidget.h"
#include "ShopWidget.h"
#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "Weapon.h"
#include "Components/Button.h"

void UShopSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (IconBtn != nullptr)
	{
		IconBtn->OnClicked.AddDynamic(this, &UShopSlotWidget::SlotBtnClicked);
	}

	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	mShopWidget = controller->GetShopWidget();
}

void UShopSlotWidget::SlotBtnClicked()
{
	if (mWeapon == nullptr)
	{
		mShopWidget->SetWeaponNameText(FText::FromString(FString::Printf(TEXT(""))));
		mShopWidget->SetWeaponAttackText(0);
		mShopWidget->SetWeaponPriceText(0);
		mShopWidget->SelectWeapon(nullptr);
	}
	else
	{
		mShopWidget->SetWeaponNameText(FText::FromName(mWeapon->GetWeaponName()));
		mShopWidget->SetWeaponAttackText(mWeapon->GetWeaponAttack());
		mShopWidget->SetWeaponPriceText(mWeapon->GetWeaponPrice());
		mShopWidget->SelectWeapon(mWeapon);
	}
}
