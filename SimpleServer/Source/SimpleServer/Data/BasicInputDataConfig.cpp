// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicInputDataConfig.h"
#include "InputMappingContext.h"
#include "InputAction.h"

UBasicInputDataConfig::UBasicInputDataConfig()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/SimpleServer/StartMap/Input/IMC_Default.IMC_Default'") };
		check(Asset.Succeeded());
		InputMappingContext = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/SimpleServer/StartMap/Input/IA_Move.IA_Move'") };
		check(Asset.Succeeded());
		Move = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/SimpleServer/StartMap/Input/IA_LookMouse.IA_LookMouse'") };
		check(Asset.Succeeded());
		LookMouse = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/SimpleServer/StartMap/Input/IA_Jump.IA_Jump'") };
		check(Asset.Succeeded());
		Jump = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/SimpleServer/StartMap/Input/IA_Evade.IA_Evade'") };
		check(Asset.Succeeded());
		Evade = Asset.Object;
	}
}