// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerCombatUserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/StatusComponent.h"

void UPlayerCombatUserWidget::RefreshStaminaBar()
{
	if (StatusComponent->MaxStamina != 0)
	{
		const float Percent = StatusComponent->CurrentStamina / StatusComponent->MaxStamina;
		StaminaBar->SetPercent(Percent);
	}
}
