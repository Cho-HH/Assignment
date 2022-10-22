// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InvenAndShopWIdget.h"
#include "ShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UShopWidget : public UInvenAndShopWidget
{
	GENERATED_BODY()
	
public:
	void SelectWeapon(class AWeapon* weapon);

	void SetWeaponText(FString name, int32 attack, int32 price);

protected:
	virtual void NativeConstruct() override;

private:

	UPROPERTY(meta = (BindWidget))
		class UButton* BuyBtn;

	UFUNCTION()
		void BuyBtnClicked();

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* WeaponPrice;

	class AWeapon* mSelectedWeapon;
};
