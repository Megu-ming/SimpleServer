// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StatusComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UI/PlayerCombatUserWidget.h"
#include "Components/TimelineComponent.h"
#include "Animation/MannyAnimInstance.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));

	USkeletalMeshComponent* SkeletalMesh = GetMesh();
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> Asset(TEXT("/Script/Engine.SkeletalMesh'/Game/ControlRig/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
		ensure(Asset.Object);
		SkeletalMesh->SetSkeletalMesh(Asset.Object);
	}

	SkeletalMesh->SetRelativeLocation(FVector(0., 0., -88.));
	SkeletalMesh->SetRelativeRotation(FRotator(0., -90., 0.));

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	FTransform SpringArmTransform = FTransform(FRotator(0., 0., 0.), FVector(0., 0., 52.));
	SpringArm->SetRelativeTransform(SpringArmTransform);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritRoll = false;

	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(GetRootComponent());

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	StatusComponent->MaxStamina = 60.f;
	StatusComponent->CurrentStamina = 30.f;
	StatusComponent->StaminaRegen = 0.2f;

	StatusComponent->WalkSpeed = 400.f;
	StatusComponent->JogSpeed = 400.f;
	StatusComponent->RunSpeed = 600.f;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}