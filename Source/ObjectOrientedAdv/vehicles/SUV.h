// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehicles.h"
#include "SUV.generated.h"

UCLASS()
class OBJECTORIENTEDADV_API ASUV : public AActor, public IVehicles
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
	ASUV();

protected:
	 
	virtual void BeginPlay() override;

public:	
	 
	virtual void Tick(float DeltaTime) override;

	float GetSpeed_Implementation() override;
	float GetWeight_Implementation() override;
	int GetYear_Implementation() override;
	int GetSeats_Implementation() override;

};
