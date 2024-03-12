// Fill out your copyright notice in the Description page of Project Settings.


#include "Refridgerator.h"


ARefridgerator::ARefridgerator()
{

	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> RefridgeMesh(TEXT("/Script/Engine.StaticMesh'/Game/Assets/refrigerator/source/Refrigirator.Refrigirator'"));

	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Refridgerator"));

	if (RefridgeMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(RefridgeMesh.Object);
	}

	price = 9000;

}

void ARefridgerator::BeginPlay()
{
	Super::BeginPlay();

}


void ARefridgerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
