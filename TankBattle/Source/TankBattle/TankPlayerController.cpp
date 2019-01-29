// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Tank.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Controller not possesing tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Controller possesing : %s"), *ControlledTank->GetName())
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();	

	//UE_LOG(LogTemp, Warning, TEXT("Player Looking Direction X: %s Y: %s"), *FString::FromInt(ViewPortX), *FString::FromInt(ViewPortY))
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter

	if (GetSightRayHitLocation(OUT HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find crosshair position
	int32 ViewPortX, ViewPortY;
	GetViewportSize(ViewPortX, ViewPortY);

	auto ScreenLocation = FVector2D(ViewPortX * CrossHairXLocation, ViewPortY * CrossHairYLocation);

	// Deproject screen position of crosshair to world location
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, OUT LookDirection))
	{
		// line trace through look direction, see what we hit upto maximum range
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldPosition; // Out parameter

	return APlayerController::DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		OUT CameraWorldPosition,
		OUT LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{	
	FHitResult HitResult;		//Out parameter
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		// Hit something
		HitLocation = HitResult.Location;

		return true;
	}
	HitLocation = FVector(0);
	return false;
}




