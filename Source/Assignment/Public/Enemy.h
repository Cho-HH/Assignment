// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Enemy.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class ASSIGNMENT_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	FOnAttackEndDelegate OnAttackEnd;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual float TakeDamage(float damageAmount, const struct FDamageEvent& damageEvent, class AController* eventInstigator, AActor* damageCauser) override;

private:
	UPROPERTY(EditAnywhere, category = "Stat")
		int32 mCurHP;

	UPROPERTY(EditAnywhere, category = "Stat")
		int32  mMaxHP;

	UPROPERTY(EditAnywhere, category = "Stat")
		int32 mAttack;

	UPROPERTY(VisibleAnywhere, category = "Widget")
		class UWidgetComponent* mHPWidget;

	class UHPWidget* mHPBar;

	void AttackCheck();

	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);
};
