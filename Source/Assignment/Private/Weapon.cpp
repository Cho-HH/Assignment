// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
	: mMesh(CreateDefaultSubobject< USkeletalMeshComponent>(TEXT("Weapon")))
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = mMesh;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

FString AWeapon::GetWeaponName() const
{
	return mName;
}

int32 AWeapon::GetWeaponPrice() const
{
	return mPrice;
}

int32 AWeapon::GetWeaponAttack() const
{
	return mAttack;
}

int32 AWeapon::GetWeaponSell() const
{
	return mSellPrice;
}

