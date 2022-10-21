// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API USlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void UpdateWidgetIcon();

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(EditAnywhere, Category = "UI")
		TSubclassOf<class AWeapon> mWeaponClass;

	UPROPERTY()
		class AWeapon* mWeapon;

	UPROPERTY(meta = (BindWidget))
		class UButton* IconBtn;

	UPROPERTY(meta = (BindWidget))
		class UImage* WeaponImg;
};
