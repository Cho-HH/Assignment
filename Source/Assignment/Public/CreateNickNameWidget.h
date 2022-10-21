// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreateNickNameWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UCreateNickNameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* NameBox;

	UPROPERTY(meta = (BindWidget))
		class UButton* OKButton;

	UFUNCTION()
	void OnClicked();
};
