// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehicles.h"
#include "Truck.generated.h"

UCLASS(Blueprintable)
class OBJECTORIENTEDADV_API ATruck : public AActor, public IVehicles
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float Weight;

	UPROPERTY()
	int Year;

	UPROPERTY()
	int Seats;


public:	
	// Sets default values for this actor's properties
	ATruck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetSpeed_Implementation() override;
	float GetWeight_Implementation() override;
	int GetYear_Implementation() override;
	int GetSeats_Implementation() override;

};
