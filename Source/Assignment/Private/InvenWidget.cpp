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

	UpdateCurMoney();
}

void UInvenWidget::BakcBtnClicked()
{
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	controller->closeWidget(this);
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

void UInvenWidget::SelectWeapon(AWeapon* weapon)
{
	mSelectedWeapon = weapon;
}

void UInvenWidget::UpdateWidgetImage()
{
	Slot_1->UpdateWidgetIcon();
	Slot_2->UpdateWidgetIcon();
	Slot_3->UpdateWidgetIcon();
	Slot_4->UpdateWidgetIcon();
	Slot_5->UpdateWidgetIcon();
	Slot_6->UpdateWidgetIcon();
}

bool UInvenWidget::AddInven(AWeapon* weapon)
{
	if (mCurAddIndex >= 6)
	{
		return false;
	}

	switch (mCurAddIndex)
	{
	case 0:
		Slot_1->SetSlot(weapon);
		break;
	case 1:
		Slot_2->SetSlot(weapon);
		break;
	case 2:
		Slot_3->SetSlot(weapon);
		break;
	case 3:
		Slot_4->SetSlot(weapon);
		break;
	case 4:
		Slot_5->SetSlot(weapon);
		break;
	case 5:
		Slot_6->SetSlot(weapon);
		break;
	default:
		break;
	}
	mCurAddIndex++;

	return true;
}
