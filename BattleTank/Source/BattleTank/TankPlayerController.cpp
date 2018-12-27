// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime) // Tick	
{
	Super::Tick(DeltaTime);
		// Super
		// AimTowardsCrosshair();
		AimTowardsCrosshair();
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AActor* ControlledTank =  GetControlledTank();

	if (!ControlledTank) 	
		UE_LOG(LogTemp, Error, TEXT("NO Controlled Tank"))

	else 
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank: %s"), *ControlledTank->GetName())

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	// get world location if line trace through crosshair
	// if it hits the landscape
		// tell the controlled tank to aim at this point

}

ATank* ATankPlayerController::GetControlledTank() const 
{

	return Cast<ATank>(GetPawn());
}

