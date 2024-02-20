// Fill out your copyright notice in the Description page of Project Settings.

#include "Truck.h"
#include "ObjectOrientedAdv.h"

// Sets default values
ATruck::ATruck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 50.0f;
	Weight = 5000.0f;

}

// Called when the game starts or when spawned
void ATruck::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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