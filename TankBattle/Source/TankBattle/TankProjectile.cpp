// Fill out your copyright notice in the Description page of Project Settings.

#include "TankProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ATankProjectile::ATankProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ATankProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATankProjectile::LaunchProjectile(float Speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate(true);
}
