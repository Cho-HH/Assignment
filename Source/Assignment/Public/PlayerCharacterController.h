// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void ChangeHUD();
	void OpenShop();
	void OpenInven();

	void closeWidget(class UUserWidget* closeWidget);

	class UShopWidget* GetShopWidget() const;
	class UInvenWidget* GetInvenWidget() const;
	bool AddInven(class AWeapon* weapon);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UHUDWidget> mHUDWidgetClass;

	UPROPERTY()
	class UHUDWidget* mHUDWidget;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UCreateNickNameWidget> mStartWidgetClass;

	UPROPERTY()
	class UCreateNickNameWidget* mStartWidget;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<class UShopWidget> mShopWidgetClass;

	UPROPERTY()
		class UShopWidget* mShopWidget;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<class UInvenWidget> mInvenWidgetClass;

	UPROPERTY()
		class UInvenWidget* mInvenWidget;

	class APlayerCharacterState* mState;

};
