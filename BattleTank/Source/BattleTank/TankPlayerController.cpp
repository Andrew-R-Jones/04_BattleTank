// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AActor* ControlledTank =  GetControlledTank();

	if (!ControlledTank) 	
		UE_LOG(LogTemp, Error, TEXT("NO Controlled Tank"))

	else 
		UE_LOG(LogTemp, Warning, TEXT("Player Controlled Tank: %s"), *ControlledTank->GetName())

}

ATank* ATankPlayerController::GetControlledTank() const 
{

	return Cast<ATank>(GetPawn());
}

