// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// FVector MoveAPlatform(FVector CurrLocation);

	// UPROPERTY(EditAnywhere)
	// double Bound = 100.0;

	// UPROPERTY(EditAnywhere)
	// FVector MyVector;

	UPROPERTY(EditAnywhere)
	// 0: forward, 1: backward
	int32 Direction = 1;

	// UPROPERTY(EditAnywhere)
	// double ForwardBound = 0.0;
	// double ReverseBound = 0.0;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);

	FVector StartLocation;

	UPROPERTY(EditAnywhere)
	float DistanceFromStart;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveBound = 100;



};
