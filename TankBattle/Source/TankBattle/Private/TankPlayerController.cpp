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

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	

	AimTowardsCrosshair();

}
ATank* ATankPlayerController::getControlledTank() const {
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair() {
	if (!getControlledTank()) { return; }

	FVector hitLocation;
	if (getSightRayHitLocation(hitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *hitLocation.ToString());
	}
}

bool ATankPlayerController::getSightRayHitLocation(FVector& outHitLocation) const {
	outHitLocation = FVector(1.0f);
	return true;
}



