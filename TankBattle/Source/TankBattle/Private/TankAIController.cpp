// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto controlledTank = getControlledTank();
	auto playerTank = getPlayerTank();
	if (!controlledTank || !playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("mijo la estas cagando"), );
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I am controlling %s"), *controlledTank->GetName());
		UE_LOG(LogTemp, Warning, TEXT("And player is %s"), *playerTank->GetName());
	}
}

ATank * ATankAIController::getPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank* ATankAIController::getControlledTank() const {
	return Cast<ATank>(GetPawn());
}
