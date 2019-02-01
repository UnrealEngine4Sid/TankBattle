// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "TankProjectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{

	AimingComponent->AimAt(HitLocation, ProjectileLaunchSpeed);
	
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurretComponent* TurretToSet)
{
	AimingComponent->SetTurrestReference(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrel) { return; }

	FVector ProjectileSpawnLocation = Barrel->GetSocketLocation(FName("Projectile"));
	FRotator ProjectileSpawnRotation = Barrel->GetSocketRotation(FName("Projectile"));

	// Spawn projectile
	ATankProjectile* Projectile = GetWorld()->SpawnActor<ATankProjectile>(
		ProjectileBlueprint, 
		ProjectileSpawnLocation, 
		ProjectileSpawnRotation
	);

	// Launch projectile
	Projectile->LaunchProjectile(ProjectileLaunchSpeed);

}