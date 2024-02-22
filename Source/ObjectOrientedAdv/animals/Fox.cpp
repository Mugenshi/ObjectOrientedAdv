// Fill out your copyright notice in the Description page of Project Settings.

#include "Fox.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
AFox::AFox()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> FoxMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/AnimalVarietyPack/Fox/Meshes/SK_Fox.SK_Fox'"));

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> FoxAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/BP_AIAnimal/AB_Fox.AB_Fox'"));

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	if (FoxMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(FoxMesh.Object);
		GetMesh()->SetAnimInstanceClass(FoxAnim.Object->GeneratedClass);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
		GetMesh()->SetRelativeScale3D(FVector(2.0f, 2.0f, 2.0f));

		Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Capsule->SetCapsuleHalfHeight(88.0f);
		Capsule->SetCapsuleRadius(88.0f);
	}

	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetMovementComponent());

	MovementPtr->MaxWalkSpeed = 150.0f;

	Name = "Fox";

}

// Called when the game starts or when spawned
void AFox::BeginPlay()
{
	Super::BeginPlay();

	DecideNextAction_Implementation(true);
	
}

// Called every frame
void AFox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFox::DecideNextAction_Implementation(bool SkipDelay)
{
	if (SkipDelay)
	{
		UObject* PtrFox = this;
		IAnimals* FoxInterface = Cast<IAnimals>(PtrFox);
		if (FoxInterface)
		{
			FoxInterface->RandomRoam_Implementation();
		}
	}
	else
	{
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &AFox::RandomRoam_Implementation, FMath::RandRange(1, 20), false);
	}
}

void AFox::RandomRoam_Implementation()
{
	const FVector Origin = GetActorLocation();

	FVector RandomLocation;
	bool LocationFound = UNavigationSystemV1::K2_GetRandomReachablePointInRadius(this, Origin, RandomLocation, 3000.0f);

	if (LocationFound)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), RandomLocation);
		DecideNextAction_Implementation(false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No location found"));
	}
}

FString AFox::GetName_Implementation()
{
	return Name;
}
