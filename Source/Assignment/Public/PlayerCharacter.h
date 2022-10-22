// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class ASSIGNMENT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
	void ChangeWeapon(UClass* weaponClass);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, category = "Camera")
		class USpringArmComponent* mSpringArm;

	UPROPERTY(VisibleAnywhere, category = "Camera")
		class UCameraComponent* mCamera;

	UPROPERTY(VisibleAnywhere, category = "Weapon")
		USkeletalMeshComponent* mWeapon;

	void MoveForward(float axis);
	void MoveRight(float axis);
	void OpenShop();
	void OpenInven();

	FVector mDirection;

	class APlayerCharacterController* mController;
	class APlayerCharacterState* mState;

	class AWeapon* mCurWeapon;

	UPROPERTY(EditAnywhere, category = "Weapon")
		TSubclassOf<class AWeapon> defaultWeaponClass;
};
