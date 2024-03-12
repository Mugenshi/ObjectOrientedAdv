// Fill out your copyright notice in the Description page of Project Settings.


#include "TV.h"

// Sets default values
ATV::ATV()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> TVMesh(TEXT("/Script/Engine.StaticMesh'/Game/AssetsvilleTown/Meshes/InteriorProps/Office/SM_TV_01.SM_TV_01'"));

	UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TV"));

	if (TVMesh.Succeeded())
	{
		MeshComponent->SetStaticMesh(TVMesh.Object);
	}

	price = 1000;

}

 
void ATV::BeginPlay()
{
	Super::BeginPlay();
	
}

 
void ATV::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

