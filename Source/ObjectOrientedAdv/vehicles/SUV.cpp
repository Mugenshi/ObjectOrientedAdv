// Fill out your copyright notice in the Description page of Project Settings.

#include "SUV.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ASUV::ASUV()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 80.0f;
	Weight = 3000.0f;
	Year = 1996;
	Seats = 5;

}

 
void ASUV::BeginPlay()
{
	Super::BeginPlay();
	
}

 
void ASUV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ASUV::GetSpeed_Implementation()
{
	return Speed;
}

float ASUV::GetWeight_Implementation()
{
	return Weight;
}

int ASUV::GetYear_Implementation()
{
	return Year;
}

int ASUV::GetSeats_Implementation()
{
	return Seats;
}


