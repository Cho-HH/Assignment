// Fill out your copyright notice in the Description page of Project Settings.


#include "HPWidget.h"
#include "Components/ProgressBar.h"

void UHPWidget::SetHPPercent(float percent)
{
	HPBar->SetPercent(percent);
}
