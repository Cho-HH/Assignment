// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlotWidget.h"
#include "ShopSlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UShopSlotWidget : public USlotWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

private:
	class UShopWidget* mShopWidget;

	UFUNCTION()
	virtual void SlotBtnClicked();
};
