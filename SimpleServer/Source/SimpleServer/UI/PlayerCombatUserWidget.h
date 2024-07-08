// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCombatUserWidget.generated.h"

class UProgressBar;
class UStatusComponent;

UCLASS()
class SIMPLESERVER_API UPlayerCombatUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void RefreshStaminaBar();

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UProgressBar* StaminaBar;

public:
	UPROPERTY(BlueprintReadWrite)
	UStatusComponent* StatusComponent;
};
