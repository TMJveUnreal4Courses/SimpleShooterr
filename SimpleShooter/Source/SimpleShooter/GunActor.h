// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunActor.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGunActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunActor();
	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root = nullptr;
	
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh = nullptr;
	
	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash = nullptr;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound = nullptr;

	UPROPERTY(EditAnywhere)
		USoundBase* BulletRicochetSound = nullptr;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactEffects = nullptr;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000.f;

	UPROPERTY(EditAnywhere)
		float Damage = 10.f;
	
	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	AController* GetOwnerController() const;
};
