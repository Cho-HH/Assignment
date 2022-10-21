// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotWidget.h"
#include "Weapon.h"
#include "Components/Image.h"

void USlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UpdateWidgetIcon();
}

void USlotWidget::UpdateWidgetIcon()
{
	if (mWeaponClass != nullptr && WeaponImg != nullptr)
	{
		WeaponImg->SetBrushFromTexture(LoadObject<UTexture2D>(nullptr, TEXT("/Game/CraftResourcesIcons/Textures/Tex_tools_01_b.Tex_tools_01_b")));
		if (mWeapon == nullptr)
		{
			mWeapon = NewObject<AWeapon>(this, mWeaponClass);
		}
	}
}
