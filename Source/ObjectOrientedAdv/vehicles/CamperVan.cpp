// Fill out your copyright notice in the Description page of Project Settings.


#include "CamperVan.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ACamperVan::ACamperVan()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 60.0f;
	Weight = 2000.0f;
	Year = 1985;
	Seats = 2;

}

// Called when the game starts or when spawned
void ACamperVan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamperVan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ACamperVan::GetSpeed_Implementation()
{
	return Speed;
}

float ACamperVan::GetWeight_Implementation()
{
	return Weight;
}

int ACamperVan::GetYear_Implementation()
{
	return Year;
}

int ACamperVan::GetSeats_Implementation()
{
	return Seats;
}


