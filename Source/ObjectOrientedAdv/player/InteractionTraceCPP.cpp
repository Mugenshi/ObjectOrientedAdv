// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionTraceCPP.h"

// Sets default values for this component's properties
UInteractionTraceCPP::UInteractionTraceCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	Length = 1000.0f;
	InteractDuration = 0.0f;
}


// Called when the game starts
void UInteractionTraceCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionTraceCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// void UInteractionTraceCPP::Trace()
// {
// 	APlayerCameraManager* CameraManager;
// 	FVector Start = GetActorLocation(CameraManager->GetPlayerCameraManager(0));
// 	FVector End = Start + GetActorForwardVector(GetActorRotation(CameraManager->GetPlayerCameraManager(0))) * Length;
// 	struct FHitResult OutHit;

// 	bool condition = LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility);
// }

