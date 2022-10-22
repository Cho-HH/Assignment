// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ASSIGNMENT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	class UMyAnimInstance* animInstance;

	UPROPERTY(EditAnywhere, category = "Weapon")
		TSubclassOf<class AWeapon> defaultWeaponClass;

	void Attack();

	bool AttackCheck(FHitResult& hitResult);
};
