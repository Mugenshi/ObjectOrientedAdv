// Fill out your copyright notice in the Description page of Project Settings.

#include "SportsCar.h"
#include "ObjectOrientedAdv.h"

// Sets default values
ASportsCar::ASportsCar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 100.0f;
	Weight = 2000.0f;

}

// Called when the game starts or when spawned
void ASportsCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
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
