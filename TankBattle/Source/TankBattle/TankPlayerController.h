// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward Declaration
class ATank;

UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	//Start moving tank barrels towards cross hair
	void AimTowardsCrosshair();
	// return OUT location, return true if hit something
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	// return look direction of camera
	bool GetLookDirection(FVector2D, FVector&) const;
	// get hit location of look vector
	bool GetLookVectorHitLocation(FVector, FVector&) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f;
};
