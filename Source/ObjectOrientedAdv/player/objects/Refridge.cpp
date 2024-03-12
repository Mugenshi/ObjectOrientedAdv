// Fill out your copyright notice in the Description page of Project Settings.


#include "Refridge.h"

// Sets default values
ARefridge::ARefridge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARefridge::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARefridge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

