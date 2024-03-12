// Fill out your copyright notice in the Description page of Project Settings.


#include "Pig.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"


APig::APig()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> PigMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/AnimalVarietyPack/Pig/Meshes/SK_Pig.SK_Pig'"));
	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> PigAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/BP_AIAnimal/AB_Pig.AB_Pig'"));

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	if (PigMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(PigMesh.Object);
		GetMesh()->SetAnimInstanceClass(PigAnim.Object->GeneratedClass);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

		Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Capsule->SetCapsuleHalfHeight(88.0f);
		Capsule->SetCapsuleRadius(88.0f);

	}

	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetMovementComponent());

	MovementPtr->MaxWalkSpeed = 150.0f;

	Name = "Pig";
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
