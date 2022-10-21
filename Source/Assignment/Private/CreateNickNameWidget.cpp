// Fill out your copyright notice in the Description page of Project Settings.


#include "CreateNickNameWidget.h"
#include "PlayerCharacterState.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacterController.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"

void UCreateNickNameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (OKButton != nullptr)
	{
		OKButton->OnClicked.AddDynamic(this, &UCreateNickNameWidget::OnClicked);
	}
}

void UCreateNickNameWidget::OnClicked()
{
	FString name = NameBox->GetText().ToString();
	if (name.Len() <= 0)
	{
		return;
	}
	
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
	APlayerCharacterState* state = Cast<APlayerCharacterState>(controller->PlayerState);
	state->SetName(name);
	controller->ChangeHUD();
}