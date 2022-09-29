// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/GameEngine.h"
#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	// ReverseBound = MyVector.Y - Bound;
	// ForwardBound = MyVector.Y + Bound;
}

// FVector AMovingPlatform::MoveAPlatform(FVector CurrLocation)
// {
// 	FString mystr = CurrLocation.ToString();
// 	UE_LOG(LogTemp, Warning, TEXT("%s"), *mystr);

// 	if (Direction == 0){
// 		if (CurrLocation.Y < ForwardBound){
// 			return (CurrLocation + FVector(0, 1, 0));
// 		} 
// 	} else if (CurrLocation.Y > ReverseBound){
// 			return (CurrLocation - FVector(0, 1, 0));
// 	} 
// 	Direction = !Direction;
// 	return CurrLocation;
// }
		


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	// Multiplying by DeltaTime makes the game Frame-Rate Independent
	// Each second, instead of each frame, move one unit!
	Super::Tick(DeltaTime);
	// SetActorLocation(MoveAPlatform(GetActorLocation()));
	FVector CurrLocation;
	
	CurrLocation = GetActorLocation() + (DeltaTime * PlatformVelocity);

	SetActorLocation(CurrLocation);
	DistanceFromStart = FVector::Distance(CurrLocation, StartLocation);
	if (DistanceFromStart > MoveBound){
		// To avoid overshot, use the following 2 lines
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveBound;
		SetActorLocation(StartLocation);
		// change direction
		PlatformVelocity = -PlatformVelocity;
	}
}

