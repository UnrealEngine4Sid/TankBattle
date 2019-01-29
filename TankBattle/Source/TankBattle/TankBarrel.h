// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hideCategories=("Collision"))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward and +1 is max upward
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category="_Setup")
	float MaxDegreePerSecond = 5;
	UPROPERTY(EditAnywhere, Category = "_Setup")
	float MaxElevationDegree = 30;
	UPROPERTY(EditAnywhere, Category = "_Setup")
	float MinElevationDegree = 0;
};
