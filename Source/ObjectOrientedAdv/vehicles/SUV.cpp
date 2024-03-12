// Fill out your copyright notice in the Description page of Project Settings.

#include "SUV.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ASUV::ASUV()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 80.0f;
	Weight = 3000.0f;
	Year = 1996;
	Seats = 5;

}

// Called when the game starts or when spawned
void ASUV::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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


