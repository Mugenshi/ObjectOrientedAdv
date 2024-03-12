// Fill out your copyright notice in the Description page of Project Settings.

#include "Wolf.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "ObjectOrientedAdv/animals/Wolf.h"

// Sets default values
AWolf::AWolf()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> WolfMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/AnimalVarietyPack/Wolf/Meshes/SK_Wolf.SK_Wolf'"));

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> WolfAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/BP_AIAnimal/AB_Wolf.AB_Wolf'"));

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	if (WolfMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(WolfMesh.Object);
		GetMesh()->SetAnimInstanceClass(WolfAnim.Object->GeneratedClass);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

		Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Capsule->SetCapsuleHalfHeight(88.0f);
		Capsule->SetCapsuleRadius(88.0f);
	}

	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetMovementComponent());

	MovementPtr->MaxWalkSpeed = 150.0f;

	Name = "Wolf";

}

 
void AWolf::BeginPlay()
{
	Super::BeginPlay();

	DecideNextAction_Implementation(true);
	
}

 
void AWolf::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

 
void AWolf::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWolf::DecideNextAction_Implementation(bool SkipDelay)
{
	if (SkipDelay)
	{
		UObject* PtrWolf = this;
		IAnimals* WolfInterface = Cast<IAnimals>(PtrWolf);
		if (WolfInterface)
		{
			WolfInterface->RandomRoam_Implementation();
		}
	}
	else
	{
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &AWolf::RandomRoam_Implementation, FMath::RandRange(1, 5), false);
	}
}

void AWolf::RandomRoam_Implementation()
{

	const FVector Origin = GetActorLocation();

	FVector RandomLocation;
	bool LocationFound = UNavigationSystemV1::K2_GetRandomReachablePointInRadius(this, Origin, RandomLocation, 1500.0f);

	if (LocationFound)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), RandomLocation);
		DecideNextAction_Implementation(false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Location not found"));
	}
}

FString AWolf::GetName_Implementation()
{
	return Name;
}
