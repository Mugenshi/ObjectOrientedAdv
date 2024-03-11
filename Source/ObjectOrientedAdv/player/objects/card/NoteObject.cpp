// Fill out your copyright notice in the Description page of Project Settings.


#include "NoteObject.h"

// Sets default values
ANoteObject::ANoteObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANoteObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANoteObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

