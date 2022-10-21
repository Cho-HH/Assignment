// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateHPBar();
	void UpdateName(const FString& name);
	
protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HPBar;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* NickNameText;

	UPROPERTY(meta = (BindWidget))
		class UButton* Shop;

	UPROPERTY(meta = (BindWidget))
		class UButton* Inven;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* HPPercent;

	UFUNCTION()
		void ShopBtnClicked();

	UFUNCTION()
		void InvenBtnClicked();

	class APlayerCharacterController* mController;
	class APlayerCharacterState* mState;
};
