// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 120.0f;
	Weight = 2500.0f;
	Year = 1984;
	Seats = 2;

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float APickup::GetSpeed_Implementation()
{
	return Speed;
}

float APickup::GetWeight_Implementation()
{
	return Weight;
}


int APickup::GetYear_Implementation()
{
	return Year;
}

int APickup::GetSeats_Implementation()
{
	return Seats;
}


