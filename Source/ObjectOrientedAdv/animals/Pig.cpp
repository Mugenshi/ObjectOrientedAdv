// Fill out your copyright notice in the Description page of Project Settings.


#include "Pig.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"


APig::APig()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(88.0f);

	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetMovementComponent());

	MovementPtr->MaxWalkSpeed = 150.0f;

	Name = "Pig";

	Say = "Oink";

	Type = "Omnivore";
}


void APig::BeginPlay()
{
	Super::BeginPlay();

	DecideNextAction_Implementation(true);
	
}


void APig::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APig::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void APig::DecideNextAction_Implementation(bool SkipDelay)
{
	if (SkipDelay)
	{
		UObject* PtrPig = this;
		IAnimals* PigInterface = Cast<IAnimals>(PtrPig);
		if (PigInterface)
		{
			PigInterface->RandomRoam_Implementation();
		}
	}
	else{
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &APig::RandomRoam_Implementation, FMath::RandRange(1, 20), false);
	
	}
}

void APig::RandomRoam_Implementation()
{

	const FVector Origin = GetActorLocation();

	FVector RandomLocation;
	bool LocationFound = UNavigationSystemV1::K2_GetRandomReachablePointInRadius(this, Origin, RandomLocation, 3000.0f);

	if (LocationFound)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), RandomLocation);
		DecideNextAction_Implementation(false);
	}
	else{
		UE_LOG(LogTemp, Warning, TEXT("No location found"));
	}

}

FString APig::GetName_Implementation()
{
	return Name;
}

FString APig::GetType_Implementation()
{
	return Type;
}

FString APig::GetSay_Implementation()
{
	return Say;
}
