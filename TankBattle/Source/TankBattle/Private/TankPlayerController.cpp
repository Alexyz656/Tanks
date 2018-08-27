// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto controlledTank = getControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("mijo la estas cagando"), );
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("I am ihjuegrgiyufdeswygudfsygusfde %s"), *controlledTank->GetName());
	}
}

ATank* ATankPlayerController::getControlledTank() const {
	return Cast<ATank>(GetPawn());
}




