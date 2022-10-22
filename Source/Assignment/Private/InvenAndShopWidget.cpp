// Fill out your copyright notice in the Description page of Project Settings.


#include "InvenAndShopWidget.h"
#include "PlayerCharacterState.h"
#include "Weapon.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacterController.h"

void UInvenAndShopWidget::NativeConstruct()
{
	Super::NativeConstruct();
	mController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	mState = Cast<APlayerCharacterState>(mController->PlayerState);

	if (BackBtn != nullptr)
	{
		BackBtn->OnClicked.AddDynamic(this, &UInvenAndShopWidget::BakcBtnClicked);
	}

	UpdateCurMoney();
}
void UInvenAndShopWidget::SetWeaponText(FString name, int32 attack)
{
	if (WeaponName != nullptr)
	{
		WeaponName->SetText(FText::FromString(name));
	}

	if (WeaponAttack != nullptr)
	{
		WeaponAttack->SetText(FText::FromString(FString::FromInt(attack)));
	}
}

void UInvenAndShopWidget::UpdateCurMoney()
{
	if (CurMoneyText != nullptr)
	{
		CurMoneyText->SetText(FText::FromString(FString::FromInt(mState->GetCurMoney())));
	}
}

void UInvenAndShopWidget::BakcBtnClicked()
{
	mController->closeWidget(this);
}
