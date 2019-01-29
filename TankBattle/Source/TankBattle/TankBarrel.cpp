// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float ElvationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElvationChange;	
	float FinalElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegree, MaxElevationDegree);
	
	SetRelativeRotation(FRotator(FinalElevation,0,0));
}
