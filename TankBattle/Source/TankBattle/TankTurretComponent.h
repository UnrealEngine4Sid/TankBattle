// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurretComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hideCategories = ("Collision"))
class TANKBATTLE_API UTankTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Rotate(float RelativeSpeed);
	
private:

	UPROPERTY(EditAnywhere, Category = "_Setup")
	float MaxDegreePerSecond = 5;
};
