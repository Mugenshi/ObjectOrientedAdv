// Fill out your copyright notice in the Description page of Project Settings.

#include "Deer.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "ObjectOrientedAdv/ObjectOrientedAdv.h"

// Sets default values
ADeer::ADeer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> DeerMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/AnimalVarietyPack/DeerStagAndDoe/Meshes/SK_DeerDoe.SK_DeerDoe'"));

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> DeerAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/BP_AIAnimal/AB_Deer.AB_Deer'"));

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	if (DeerMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(DeerMesh.Object);
		GetMesh()->SetAnimInstanceClass(DeerAnim.Object->GeneratedClass);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

		Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Capsule->SetCapsuleHalfHeight(88.0f);
		Capsule->SetCapsuleRadius(88.0f);

	}

	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetMovementComponent());

	MovementPtr->MaxWalkSpeed = 150.0f;

	Name = "Deer";

}

// Called when the game starts or when spawned
void ADeer::BeginPlay()
{
	Super::BeginPlay();

	DecideNextAction_Implementation(true);
	
}

// Called every frame
void ADeer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADeer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADeer::DecideNextAction_Implementation(bool SkipDelay)
{
	if (SkipDelay)
	{
		UObject* PtrDeer = this;
		IAnimals* DeerInterface = Cast<IAnimals>(PtrDeer);
		if (DeerInterface) {
			DeerInterface->RandomRoam_Implementation();
		}
	}
	else
	{
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ADeer::RandomRoam_Implementation, FMath::RandRange(1, 20), false);
	}
}

void ADeer::RandomRoam_Implementation()
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

FString ADeer::GetName_Implementation()
{
	return Name;
}
