// Fill out your copyright notice in the Description page of Project Settings.


#include "Monitor.h"

// Sets default values
AMonitor::AMonitor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

 
void AMonitor::BeginPlay()
{
	Super::BeginPlay();
	
}

 
void AMonitor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

