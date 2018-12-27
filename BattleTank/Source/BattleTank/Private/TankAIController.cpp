// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	AActor* AIPlayerController = GetAIControlledTank();

	if (!AIPlayerController)
		UE_LOG(LogTemp, Error, TEXT("No AI Controller possessed"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI Possessed Tank: %s"), *AIPlayerController->GetName())


	AActor* FirstPlayerController = GetPlayerTank();

	if (!FirstPlayerController)
		UE_LOG(LogTemp, Error, TEXT("AI Controller Cant Find First Player Controller Tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("First Player Controller Tank Found: %s"), *FirstPlayerController->GetName())
	

}


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto FirstPlayerControllerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	 return Cast<ATank>(FirstPlayerControllerPawn);

	
}

