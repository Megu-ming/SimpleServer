// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BasicInputDataConfig.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class SIMPLESERVER_API UBasicInputDataConfig : public UObject
{
	GENERATED_BODY()
	
public:
	UBasicInputDataConfig();
	UInputMappingContext* InputMappingContext = nullptr;

public:
	UInputAction* Move = nullptr;
	UInputAction* LookMouse = nullptr;
	UInputAction* Jump = nullptr;
	UInputAction* Evade = nullptr;
};
