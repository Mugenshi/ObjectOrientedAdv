// Fill out your copyright notice in the Description page of Project Settings.


#include "CarSale.h"


ACarSale::ACarSale()
{
	
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CarMesh(TEXT("/Script/Engine.StaticMesh'/Game/Assets/SM_Hatchback_Sell.SM_Hatchback_Sell'"));

	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CarSale"));

	if (CarMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(CarMesh.Object);
	}

	price = 40000;

}

void ACarSale::BeginPlay()
{
	Super::BeginPlay();

}


void ACarSale::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
