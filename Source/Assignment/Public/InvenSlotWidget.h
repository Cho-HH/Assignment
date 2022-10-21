// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlotWidget.h"
#include "InvenSlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UInvenSlotWidget : public USlotWidget
{
	GENERATED_BODY()
	
public:
	void SetSlot(class AWeapon* weapon);

protected:
	virtual void NativeConstruct() override;

private:
	class UInvenWidget* mInvenWidget;

	UFUNCTION()
	virtual void SlotBtnClicked();

	
};
