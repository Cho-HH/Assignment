// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacterController.h"
#include "HUDWidget.h"
#include "CreateNickNameWidget.h"
#include "PlayerCharacterState.h"
#include "Kismet/GameplayStatics.h"
#include "InvenWidget.h"
#include "ShopWidget.h"
#include "Weapon.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	mStartWidget = CreateWidget<UCreateNickNameWidget>(this, mStartWidgetClass);
	mStartWidget->AddToViewport();

	bShowMouseCursor = true;
	GetPawn()->DisableInput(this);

	mState = Cast<APlayerCharacterState>(PlayerState);

	mShopWidget = CreateWidget<UShopWidget>(this, mShopWidgetClass);
	mShopWidget->AddToViewport();
	mShopWidget->SetVisibility(ESlateVisibility::Hidden);
	mInvenWidget = CreateWidget<UInvenWidget>(this, mInvenWidgetClass);
	mInvenWidget ->AddToViewport();
	mInvenWidget ->SetVisibility(ESlateVisibility::Hidden);
}

void APlayerCharacterController::ChangeHUD()
{
	mStartWidget->RemoveFromViewport();
	mHUDWidget = CreateWidget<UHUDWidget>(this, mHUDWidgetClass);
	mHUDWidget->AddToViewport();
	mHUDWidget->UpdateName(mState->GetPlayerName());
	mHUDWidget->UpdateHPBar();
	GetPawn()->EnableInput(this);
}

void APlayerCharacterController::OpenShop()
{
	SetPause(true);
	mHUDWidget->SetVisibility(ESlateVisibility::Hidden);
	mShopWidget->SetVisibility(ESlateVisibility::Visible);
	mShopWidget->UpdateCurMoney();
}

void APlayerCharacterController::OpenInven()
{
	SetPause(true);
	mHUDWidget->SetVisibility(ESlateVisibility::Hidden);
	mInvenWidget->SetVisibility(ESlateVisibility::Visible);
	mInvenWidget->UpdateWidgetImage();
	mInvenWidget->UpdateCurMoney();
}

void APlayerCharacterController::closeWidget(UUserWidget* closeWidget)
{
	SetPause(false);
	closeWidget->SetVisibility(ESlateVisibility::Hidden);
	mHUDWidget->SetVisibility(ESlateVisibility::Visible);
	mHUDWidget->UpdateName(mState->GetPlayerName());
	mHUDWidget->UpdateHPBar();
}

UShopWidget* APlayerCharacterController::GetShopWidget() const
{
	return mShopWidget;
}

UInvenWidget* APlayerCharacterController::GetInvenWidget() const
{
	return mInvenWidget;
}

bool APlayerCharacterController::AddInven(AWeapon* weapon)
{
	return mInvenWidget->AddInven(weapon);
}
