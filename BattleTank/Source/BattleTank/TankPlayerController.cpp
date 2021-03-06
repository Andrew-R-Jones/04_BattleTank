// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"

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
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
	

}

void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector OutHitLocation; // out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // Has "side-effect, is going to line trace
	{
		// Tell the controlled tank to aim at this point
		AimingComponent->AimAt(OutHitLocation);
	}

}
// get world location of line trace through cross hair, true if hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;
	// De-project the screen position of the cross hair to a world direction
	if (GetLookDiretion(ScreenLocation, LookDirection))
	{
		// Line-trace along that LookDirection and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);		
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation, 
		EndLocation, 
		ECollisionChannel::ECC_Visibility)
		)
	{
		// set OUTHitLocation
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0.0f);
		return false;
}



bool ATankPlayerController::GetLookDiretion(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
}

