// Fill out your copyright notice in the Description page of Project Settings.


#include "lightbulb.h"

// Sets default values
Alightbulb::Alightbulb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Alightbulb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Alightbulb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

