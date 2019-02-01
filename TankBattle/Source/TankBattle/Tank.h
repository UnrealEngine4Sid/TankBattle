// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declaration
class UTankBarrel;
class UTankAimingComponent;
class UTankTurretComponent;
class ATankProjectile;

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	// Set barrel static mesh
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurretReference(UTankTurretComponent* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Get tank aiming component
	UTankAimingComponent* AimingComponent = nullptr;

private:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = "Firing")
	float ProjectileLaunchSpeed = 5000;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<ATankProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;
};
