// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

#define OUT

// Forward declaration
class UTankBarrel; 
class UStaticMeshComponent;

// Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

public:	
	void AimAt(FVector HitLocation, float ProjectileLaunchSpeed);

	// Set barrel static mesh
	void SetBarrelReference(UTankBarrel* BarrelToSet);

private:

	// Holds barrel static mesh
	UTankBarrel* BarrelStaticMesh = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
