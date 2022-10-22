// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacterController.h"
#include "HUDWidget.h"
#include "CreateNickNameWidget.h"
#include "PlayerCharacterState.h"
#include "Kismet/GameplayStatics.h"
#include "InvenWidget.h"
#include "ShopWidget.h"
#include "Weapon.h"
#include "PlayerCharacter.h"

void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

	mStartWidget = CreateWidget<UCreateNickNameWidget>(this, mStartWidgetClass);
	mHUDWidget = CreateWidget<UHUDWidget>(this, mHUDWidgetClass);
	mShopWidget = CreateWidget<UShopWidget>(this, mShopWidgetClass);
	mInvenWidget = CreateWidget<UInvenWidget>(this, mInvenWidgetClass);

	mStartWidget->AddToViewport();

	bShowMouseCursor = true;
	GetPawn()->DisableInput(this);

	mState = Cast<APlayerCharacterState>(PlayerState);

	mHUDWidget->AddToViewport();
	mHUDWidget->SetVisibility(ESlateVisibility::Hidden);
	
	mShopWidget->AddToViewport();
	mShopWidget->SetVisibility(ESlateVisibility::Hidden);
	
	mInvenWidget ->AddToViewport();
	mInvenWidget ->SetVisibility(ESlateVisibility::Hidden);

	SetPause(true);
}

void APlayerCharacterController::ChangeHUD()
{
	SetPause(false);
	mStartWidget->RemoveFromViewport();
	mHUDWidget->SetVisibility(ESlateVisibility::Visible);
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
	mShopWidget->SetWeaponText(TEXT(""), 0, 0);
}

void APlayerCharacterController::OpenInven()
{
	SetPause(true);
	mHUDWidget->SetVisibility(ESlateVisibility::Hidden);
	mInvenWidget->SetVisibility(ESlateVisibility::Visible);
	mInvenWidget->UpdateWidgetImage();
	mInvenWidget->UpdateCurMoney();
	mInvenWidget->SetWeaponText(TEXT(""), 0, 0);
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

UHUDWidget* APlayerCharacterController::GetHUDWidget() const
{
	return mHUDWidget;
}

bool APlayerCharacterController::AddInven(AWeapon* weapon)
{
	return mInvenWidget->AddInven(weapon);
}

void APlayerCharacterController::ChangeWeapon(UClass* changeWeaponClass)
{
	APlayerCharacter* player = Cast<APlayerCharacter>(GetPawn());
	player->ChangeWeapon(changeWeaponClass);
}
