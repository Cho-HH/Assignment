// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "MyAnimInstance.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::Attack()
{
	if (animInstance != nullptr)
	{
		animInstance->PlayAttack();
	}
}

bool ABaseCharacter::AttackCheck(FHitResult& hitResult)
{
	FCollisionQueryParams queryParams(NAME_None, false, this);
	bool result = GetWorld()->SweepSingleByChannel(
		hitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * 200.f,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel1,
		FCollisionShape::MakeSphere(50.f),
		queryParams);

	return result;
}
