// Fill out your copyright notice in the Description page of Project Settings.

#include "Truck.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ATruck::ATruck()
{

	PrimaryActorTick.bCanEverTick = true;

	Speed = 50.0f;
	Weight = 5000.0f;
	Year = 1990;
	Seats = 2;
}

 
void ATruck::BeginPlay()
{
	Super::BeginPlay();
	
}

 
void ATruck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ATruck::GetSpeed_Implementation()
{
	return Speed;
}

float ATruck::GetWeight_Implementation()
{
	return Weight;
}

int ATruck::GetYear_Implementation()
{
	return Year;
}

int ATruck::GetSeats_Implementation()
{
	return Seats;
}
