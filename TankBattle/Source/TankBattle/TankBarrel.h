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
	void Elevate(float DegreePerSecond);

private:
	UPROPERTY(EditAnywhere, Category="_Setup")
	float MaxDegreePerSecond = 20;
	UPROPERTY(EditAnywhere, Category = "_Setup")
	float MaxElevationDegree = 20;
	UPROPERTY(EditAnywhere, Category = "_Setup")
	float MinElevationDegree = 0;
};
