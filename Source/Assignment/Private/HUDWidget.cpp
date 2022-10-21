// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacterController.h"
#include "PlayerCharacterState.h"

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	mController = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	mState = Cast<APlayerCharacterState>(mController->PlayerState);

	if (Shop != nullptr)
	{
		Shop->OnClicked.AddDynamic(this, &UHUDWidget::ShopBtnClicked);
	}

	if (Inven != nullptr)
	{
		Inven->OnClicked.AddDynamic(this, &UHUDWidget::InvenBtnClicked);
	}
}

void UHUDWidget::UpdateHPBar()
{
	HPBar->SetPercent(mState->GetCurHP() / mState->GetMaxHP());
	HPPercent->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), mState->GetCurHP(), mState->GetMaxHP())));
}

void UHUDWidget::UpdateName(const FString& name)
{
	NickNameText->SetText(FText::FromString(name));
}

void UHUDWidget::ShopBtnClicked()
{
	mController->OpenShop();
}

void UHUDWidget::InvenBtnClicked()
{
	mController->OpenInven();
}