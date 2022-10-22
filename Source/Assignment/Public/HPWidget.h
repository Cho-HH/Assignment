// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HPWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API UHPWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetHPPercent(float percent);

private:
	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HPBar;
};
