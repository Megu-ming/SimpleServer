// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StatusComponent.h"

// Sets default values for this component's properties
UStatusComponent::UStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UStatusComponent::DecreaseStamina(const float InAmount)
{
	const float Result = CurrentStamina - InAmount;
	if (Result < 0)
		CurrentStamina = 0;
	else
		CurrentStamina = Result;
}

