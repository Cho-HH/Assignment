// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class ASSIGNMENT_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();
	FString GetWeaponName() const;
	int32 GetWeaponPrice() const;
	int32 GetWeaponAttack() const;
	int32 GetWeaponSell() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
		USkeletalMeshComponent* mMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FString mName;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		int32 mPrice;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		int32 mAttack;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		int32 mSellPrice;
};
