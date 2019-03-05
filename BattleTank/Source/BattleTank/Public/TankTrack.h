// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	// Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// This is max force per track in Newtons SI force newtons, mass kg, acceleration m/s/s .. Force = mass * acceleration
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 489880; // assume tank (M1:60) mass is 54 tons -> 48988 kg and 1g acceleration


};
