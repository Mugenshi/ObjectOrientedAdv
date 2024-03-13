// Fill out your copyright notice in the Description page of Project Settings.

#include "SportsCar.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ASportsCar::ASportsCar()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 200.0f;
	Weight = 2000.0f;
	Year = 1982;
	Seats = 2;

}

 
void ASportsCar::BeginPlay()
{
	Super::BeginPlay();
	
}

 
void ASportsCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ASportsCar::GetSpeed_Implementation()
{
	return Speed;
}

float ASportsCar::GetWeight_Implementation()
{
	return Weight;
}

int ASportsCar::GetYear_Implementation()
{
	return Year;
}

int ASportsCar::GetSeats_Implementation()
{
	return Seats;
}


