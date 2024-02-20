// Fill out your copyright notice in the Description page of Project Settings.

#include "testDeer.h"
#include "NavigationSystem.h"
#include "Components/CapsuleComponent.h"
#include "ObjectOrientedAdv.h"

// Sets default values
AtestDeer::AtestDeer()
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

}

// Called when the game starts or when spawned
void AtestDeer::BeginPlay()
{
	Super::BeginPlay();

	DecideNextAction(true);
	
}

// Called every frame
void AtestDeer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AtestDeer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AtestDeer::DecideNextAction(bool SkipDelay)
{
	if (SkipDelay)
	{
		RandomRoam();
	}
	else
	{
		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &AtestDeer::RandomRoam, FMath::RandRange(1, 5), false);
	}
}

void AtestDeer::RandomRoam()
{
	UCharacterMovementComponent* MovementPtr = Cast<UCharacterMovementComponent>(GetMovementComponent());

	MovementPtr->MaxWalkSpeed = 150.0f;

	const FVector Origin = GetActorLocation();

	FVector RandomLocation;
	bool LocationFound = UNavigationSystemV1::K2_GetRandomReachablePointInRadius(this, Origin, RandomLocation, 1500.0f);

	if (LocationFound)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), RandomLocation);
		DecideNextAction(false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No location found"));
	}
	
}
