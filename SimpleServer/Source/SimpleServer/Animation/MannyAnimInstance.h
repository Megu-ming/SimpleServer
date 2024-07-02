// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MannyAnimInstance.generated.h"

class APlayerCharacter;
class UCharacterMovementComponent;

UCLASS()
class SIMPLESERVER_API UMannyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY(EditAnywhere)
	APlayerCharacter* Character;
	UPROPERTY(EditAnywhere)
	UCharacterMovementComponent* MovementComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GroundSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldMove;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsFalling;
};
