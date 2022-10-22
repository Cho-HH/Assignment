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
		mShopWidget->SetWeaponText(TEXT(""), 0, 0);		
		mShopWidget->SelectWeapon(nullptr);
	}
	else
	{
		mShopWidget->SetWeaponText(mWeapon->GetWeaponName(), mWeapon->GetWeaponAttack(), mWeapon->GetWeaponPrice());
		mShopWidget->SelectWeapon(mWeapon);
	}
}
