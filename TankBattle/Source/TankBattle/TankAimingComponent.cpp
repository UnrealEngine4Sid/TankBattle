// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float ProjectileLaunchSpeed)
{	
	// do nothing if no barrel mesh set
	if (!BarrelStaticMesh) { return; }
		
	FVector OutLaunchVelocity; // out parameter
	FVector StartLocation = BarrelStaticMesh->GetSocketLocation(FName("Projectile"));
	
	bool bAimSolution = UGameplayStatics::SuggestProjectileVelocity(
							this,
							OUT OutLaunchVelocity,
							StartLocation,
							HitLocation,
							ProjectileLaunchSpeed,
							ESuggestProjVelocityTraceOption::DoNotTrace
						);


	if (bAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	BarrelStaticMesh = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// work out difference between current barrel rotation and aim direction
	auto BarrelRotator = BarrelStaticMesh->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();

	auto DeltaRotator = AimAsRotator - BarrelRotator;

	BarrelStaticMesh->Elevate(5); // TODO remove magic number
}

