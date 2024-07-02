#include "MannyAnimInstance.h"
#include "Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
// Fill out your copyright notice in the Description page of Project Settings.

void UMannyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<APlayerCharacter>(GetOwningActor());
	if (IsValid(Character))
		MovementComponent = Character->GetCharacterMovement();
}

void UMannyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Character))
	{
		Velocity = MovementComponent->Velocity;
		GroundSpeed = UKismetMathLibrary::VSizeXY(Velocity);

		FVector CurrentAcc = MovementComponent->GetCurrentAcceleration();
		bool Curr = UKismetMathLibrary::NotEqual_VectorVector(CurrentAcc, FVector(0., 0., 0.), 0.f);
		bool Ground = (GroundSpeed > 3.f);
		bShouldMove = UKismetMathLibrary::BooleanAND(Curr, Ground);

		bIsFalling = MovementComponent->IsFalling();
	}
}
