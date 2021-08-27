// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGunActor; // Forward Declaring can make the compile time more faster because we dont include big header files

UCLASS()
class SIMPLESHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	UPROPERTY(EditAnywhere)
		float RotationYRate = 55.f;

	UPROPERTY(EditAnywhere)
		float RotationXRate = 55.f;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGunActor> GunClass; // Makes A Subclass of AGunActor called GunClass
	
	UPROPERTY()
		AGunActor* Gun; // this is the actual gun
};
