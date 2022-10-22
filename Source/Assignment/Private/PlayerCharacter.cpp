// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerCharacterController.h"
#include "PlayerCharacterState.h"
#include "Weapon.h"
#include "InvenWidget.h"
#include "HUDWidget.h"
#include "MyAnimInstance.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
	: mSpringArm(CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm")))
	, mCamera(CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")))
	, mDirection(FVector::ZeroVector)
	, mWeapon(CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon")))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mSpringArm->SetupAttachment(GetCapsuleComponent());
	mCamera->SetupAttachment(mSpringArm);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	mController = Cast<APlayerCharacterController>(GetController());
	mState = Cast<APlayerCharacterState>(mController->PlayerState);

	AWeapon* weapon = Cast<AWeapon>(GetWorld()->SpawnActor<AWeapon>(defaultWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator));
	weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("hand_rSocket"));
	mCurWeapon = weapon;

	mState->SetAttack(mCurWeapon->GetWeaponAttack());
	mController->GetHUDWidget()->UpdateAttack(mState->GetAttack());

	animInstance->OnAttackHitCheck.AddUObject(this, &APlayerCharacter::AttackCheck);
}

void APlayerCharacter::ChangeWeapon(UClass* weaponClass)
{
	mController->GetInvenWidget()->AddInven(mCurWeapon);
	mCurWeapon->Destroy();
	
	AWeapon* weapon = Cast<AWeapon>(GetWorld()->SpawnActor<AWeapon>(weaponClass, FVector::ZeroVector, FRotator::ZeroRotator));
	weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("hand_rSocket"));
	mCurWeapon = weapon;

	mState->SetAttack(mCurWeapon->GetWeaponAttack());
	mController->GetHUDWidget()->UpdateAttack(mState->GetAttack());
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	if (mDirection.SizeSquared() > 0.f)
	{
		GetController()->SetControlRotation(FRotationMatrix::MakeFromX(mDirection).Rotator());
		AddMovementInput(mDirection);
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAction(TEXT("OpenShop"), EInputEvent::IE_Pressed, this, &APlayerCharacter::OpenShop);
	PlayerInputComponent->BindAction(TEXT("OpenInven"), EInputEvent::IE_Pressed, this, &APlayerCharacter::OpenInven);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Attack);
}

float APlayerCharacter::TakeDamage(float damageAmount, const FDamageEvent& damageEvent, AController* eventInstigator, AActor* damageCauser)
{
	float damage = Super::TakeDamage(damageAmount, damageEvent, eventInstigator, damageCauser);
	mState->SetCurHP(mState->GetCurHP() - damage);
	if (mState->GetCurHP() <= 0)
	{
		animInstance->SetDeadAnim();
		SetActorEnableCollision(false);
		SetActorTickEnabled(false);
	}
	UHUDWidget* hud = mController->GetHUDWidget();
	hud->UpdateHPBar();

	return damage;
}

void APlayerCharacter::MoveForward(float axis)
{
	mDirection.X = axis;
}

void APlayerCharacter::MoveRight(float axis)
{
	mDirection.Y = axis;
}

void APlayerCharacter::OpenShop()
{
	mController->OpenShop();
}

void APlayerCharacter::OpenInven()
{
	mController->OpenInven();
}

void APlayerCharacter::AttackCheck()
{
	FHitResult hitResult;
	bool result = ABaseCharacter::AttackCheck(hitResult);

	if (result)
	{
		FDamageEvent damageEvent;
		hitResult.GetActor()->TakeDamage(mState->GetAttack(), damageEvent, mController, this);
	}
}

