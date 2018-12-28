// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public: 

private:
	ATank* GetControlledTank() const;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	// start the tank moving the barrel so that a shot would hit 
	// where the cross hair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hits landscape
	bool GetSightRayHitLocation(FVector& OUTHitLocation) const;


	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;


	bool GetLookDiretion(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OUTHitLocation) const;

};