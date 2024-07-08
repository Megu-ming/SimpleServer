// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStatusComponent;
class UPlayerCombatUserWidget;
class UTimelineComponent;

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	None,
	Running
};

UCLASS()
class SIMPLESERVER_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStatusComponent* StatusComponent;
	UPROPERTY(BlueprintReadOnly)
	UPlayerCombatUserWidget* UI_PlayerCombat;
};
