// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "Gun.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> DefaultMappingContextRef(
		TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_DefaultMapping.IMC_DefaultMapping'")
	);
	if (DefaultMappingContextRef.Succeeded())
	{
		DefaultMappingContext = DefaultMappingContextRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DefaultMappingContext load fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> LookUpActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Actions/IA_LookUp.IA_LookUp'")
	);
	if (LookUpActionRef.Succeeded())
	{
		LookUpAction = LookUpActionRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LookUpAction load fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> LookRightActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Actions/IA_LookRight.IA_LookRight'")
	);
	if (LookRightActionRef.Succeeded())
	{
		LookRightAction = LookRightActionRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LookUpAction load fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> JumpActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Actions/IA_Jump.IA_Jump'")
	);
	if (JumpActionRef.Succeeded())
	{
		JumpAction = JumpActionRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("JumpAction load fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> MoveForwardActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Actions/IA_MoveForward.IA_MoveForward'")
	);
	if (MoveForwardActionRef.Succeeded())
	{
		MoveForwardAction = MoveForwardActionRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoveForwardAction load fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> MoveRightActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Actions/IA_MoveRight.IA_MoveRight'")
	);
	if (MoveRightActionRef.Succeeded())
	{
		MoveRightAction = MoveRightActionRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoveRightAction load fail"));
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> ShotActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/Actions/IA_Shot.IA_Shot'")
	);
	if (ShotActionRef.Succeeded())
	{
		ShotAction = ShotActionRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ShotAction load fail"));
	}
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
		//Subsystem->RemoveMappingContext(DefaultMappingContext);
	}

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComonent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInputComonent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AShooterCharacter::MoveForward);
	EnhancedInputComonent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AShooterCharacter::MoveRight);
	EnhancedInputComonent->BindAction(LookUpAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookUp);
	EnhancedInputComonent->BindAction(LookRightAction, ETriggerEvent::Triggered, this, &AShooterCharacter::LookRight);
	EnhancedInputComonent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	EnhancedInputComonent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComonent->BindAction(ShotAction, ETriggerEvent::Started, this, &AShooterCharacter::Shot);
}

void AShooterCharacter::MoveForward(const FInputActionValue& Value)
{
	float MoveForwardFloat = Value.Get<float>();
	AddMovementInput(GetActorForwardVector() * MoveForwardFloat);
}

void AShooterCharacter::MoveRight(const FInputActionValue& Value)
{
	float MoveRightFloat = Value.Get<float>();
	AddMovementInput(GetActorRightVector() * MoveRightFloat);
}

void AShooterCharacter::LookUp(const FInputActionValue& Value)
{
	float AxisValue = Value.Get<float>();
	AddControllerPitchInput(AxisValue * GetWorld()->GetDeltaSeconds() * RotationRate);
}

void AShooterCharacter::LookRight(const FInputActionValue& Value)
{
	float AxisValue = Value.Get<float>();
	AddControllerYawInput(AxisValue * GetWorld()->GetDeltaSeconds() * RotationRate);
}

void AShooterCharacter::Shot(const FInputActionValue& Value)
{
	Gun->PullTrigger();
}

