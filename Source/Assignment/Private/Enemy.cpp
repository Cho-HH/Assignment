// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Weapon.h"
#include "HPWidget.h"
#include "Components/WidgetComponent.h"
#include "MyAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemy::AEnemy()
	: mCurHP(300)
	, mMaxHP(300)
	, mAttack(50)
	, mHPWidget(CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBar")))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mHPWidget->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AWeapon* weapon = Cast<AWeapon>(GetWorld()->SpawnActor<AWeapon>(defaultWeaponClass, FVector::ZeroVector, FRotator::ZeroRotator));
	weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("hand_rSocket"));

	mHPBar = Cast<UHPWidget>(mHPWidget->GetUserWidgetObject());

	animInstance->OnAttackHitCheck.AddUObject(this, &AEnemy::AttackCheck);
	animInstance->OnMontageEnded.AddDynamic(this, &AEnemy::OnAttackMontageEnded);
}

float AEnemy::TakeDamage(float damageAmount, const FDamageEvent& damageEvent, AController* eventInstigator, AActor* damageCauser)
{
	float damage = Super::TakeDamage(damageAmount, damageEvent, eventInstigator, damageCauser);
	if (eventInstigator->GetClass() == GetController()->GetClass())
	{
		return damage;
	}

	mCurHP -= damage;
	mHPBar->SetHPPercent(static_cast<float>(mCurHP) / static_cast<float>(mMaxHP));
	if (mCurHP <= 0)
	{
		animInstance->SetDeadAnim();
		SetActorEnableCollision(false);
		SetActorTickEnabled(false);
		GetCharacterMovement()->bUseControllerDesiredRotation = false;
	}
	return damage;
}

void AEnemy::AttackCheck()
{
	FHitResult hitResult;
	bool result = ABaseCharacter::AttackCheck(hitResult);

	if (result)
	{
		FDamageEvent damageEvent;
		hitResult.GetActor()->TakeDamage(mAttack, damageEvent, GetController(), this);
	}
}

void AEnemy::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	OnAttackEnd.Broadcast();
}

bool AEnemy::IsAlive() const
{
	return mCurHP > 0;
}