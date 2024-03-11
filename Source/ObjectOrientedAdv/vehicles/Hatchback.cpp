// Fill out your copyright notice in the Description page of Project Settings.

#include "Hatchback.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
AHatchback::AHatchback()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 90.0f;
	Weight = 1500.0f;
	Year = 2000;
	Seats = 5;

}

// Called when the game starts or when spawned
void AHatchback::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHatchback::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AHatchback::GetSpeed_Implementation()
{
	return Speed;
}

float AHatchback::GetWeight_Implementation()
{
	return Weight;
}

int AHatchback::GetYear_Implementation()
{
	return Year;
}

int AHatchback::GetSeats_Implementation()
{
	return Seats;
}


