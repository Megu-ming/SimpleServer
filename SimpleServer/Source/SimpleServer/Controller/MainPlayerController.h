// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

struct FInputActionValue;
class APlayerCharacter;

UCLASS()
class SIMPLESERVER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMainPlayerController();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	void OnMove(const FInputActionValue& InputActionValue);
	void OnMoveReleased();
	void OnLookMouse(const FInputActionValue& InputActionValue);
	void OnJump();
	void OnEvadenRun();

private:
	APlayerCharacter* MainCharacter;

private:
	bool bIsMoving;
	UAnimMontage* FrontEvadeMontage;
};
