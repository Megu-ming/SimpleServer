#include "Controller/MainPlayerController.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Data/BasicInputDataConfig.h"
#include "Character/PlayerCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Animation/MannyAnimInstance.h"

AMainPlayerController::AMainPlayerController()
{
	{
		static ConstructorHelpers::FObjectFinder<UAnimMontage> Asset(TEXT("/Script/Engine.AnimMontage'/Game/SimpleServer/StartMap/Animation/Frank_RPG_Assassin_Evade_F_Montage.Frank_RPG_Assassin_Evade_F_Montage'"));
		ensure(Asset.Succeeded());
		EvadeMontage = Asset.Object;
	}
}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	const UBasicInputDataConfig* BasicInputDataConfig = GetDefault<UBasicInputDataConfig>();
	Subsystem->AddMappingContext(BasicInputDataConfig->InputMappingContext, 0);
	
	PlayerCameraManager->ViewPitchMin = -20.f;
	PlayerCameraManager->ViewPitchMax = 20.f;

	MainCharacter = Cast<APlayerCharacter>(GetPawn());
	ensure(MainCharacter);
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	ensure(EnhancedInputComponent);

	{
		const UBasicInputDataConfig* BasicInputDataConfig = GetDefault<UBasicInputDataConfig>();
		EnhancedInputComponent->BindAction(BasicInputDataConfig->Move, ETriggerEvent::Triggered, this, &ThisClass::OnMove);
		EnhancedInputComponent->BindAction(BasicInputDataConfig->LookMouse, ETriggerEvent::Triggered, this, &ThisClass::OnLookMouse);
		EnhancedInputComponent->BindAction(BasicInputDataConfig->Jump, ETriggerEvent::Started, this, &ThisClass::OnJump);
		EnhancedInputComponent->BindAction(BasicInputDataConfig->Evade, ETriggerEvent::Started, this, &ThisClass::OnEvade);
	}
}

void AMainPlayerController::OnMove(const FInputActionValue& InputActionValue)
{
	float ScaleValueX = InputActionValue.Get<FVector2D>().X;
	float ScaleValueY = InputActionValue.Get<FVector2D>().Y;

	float ActorRotYaw = K2_GetActorRotation().Yaw;
	FRotator ActorRot = FRotator(0., ActorRotYaw, 0.);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(ActorRot);
	FVector RightVector = UKismetMathLibrary::GetRightVector(ActorRot);

	MainCharacter->AddMovementInput(ForwardVector, ScaleValueY);
	MainCharacter->AddMovementInput(RightVector, ScaleValueX);
}

void AMainPlayerController::OnLookMouse(const FInputActionValue& InputActionValue)
{
	float ScaleValueX = InputActionValue.Get<FVector2D>().X;
	float ScaleValueY = InputActionValue.Get<FVector2D>().Y;

	AddYawInput(ScaleValueX);
	AddPitchInput(ScaleValueY);
}

void AMainPlayerController::OnJump()
{
	UAnimInstance* AnimInstance = MainCharacter->GetMesh()->GetAnimInstance();
	if(!AnimInstance->Montage_IsPlaying(EvadeMontage))
	{
		MainCharacter->Jump();
	}
}

void AMainPlayerController::OnEvade()
{
	UMannyAnimInstance* AnimInstance = Cast<UMannyAnimInstance>(MainCharacter->GetMesh()->GetAnimInstance());
	if (!AnimInstance) { return; }
	if (AnimInstance->Montage_IsPlaying(EvadeMontage)) { return; }
	if (AnimInstance->IsJump()) { return; }
	AnimInstance->Montage_Play(EvadeMontage);
}
