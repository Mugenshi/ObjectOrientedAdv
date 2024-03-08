// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPP.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCPP::APlayerCPP()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(0.5f);
	SetActorTickEnabled(true);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> QuinnMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'"));

	static ConstructorHelpers::FObjectFinder<UAnimBlueprint> QuinnAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Characters/Mannequins/Animations/ABP_Quinn.ABP_Quinn'"));

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	money = 0;

	if (QuinnMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(QuinnMesh.Object);
		GetMesh()->SetAnimInstanceClass(QuinnAnim.Object->GeneratedClass);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

		Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Capsule->SetCapsuleHalfHeight(90.0f);
		Capsule->SetCapsuleRadius(35.0f);

		Camera->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Head"));
		Camera->SetRelativeLocation(FVector(5.0f, 9.0f, 0.0f));
		Camera->SetRelativeRotation(FRotator(0.0f, 90.0f, -90.0f));
		Camera->bUsePawnControlRotation = true;

	}

}

// Called when the game starts or when spawned
void APlayerCPP::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCPP::Tick(float DeltaTime)
{
	// Call the super... it probably needs to do stuff!
	Super::Tick(DeltaTime);

	// Temporarily display debug information
	GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
		*(FString::Printf(TEXT("Keys - %d Keys Currently held"), KeyWallet.Num())));

	InteractCheck();

}

// Called to bind functionality to input
void APlayerCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APlayerCPP::AddKey(FString KeyToAdd)
{
	if (KeyWallet.Contains(KeyToAdd))
	{
		// Key already in there, play a noise
		OnKeyWalletAction.Broadcast(KeyToAdd, EPlayerKeyAction::AddKey, false);
	}
	else
	{
		KeyWallet.Add(KeyToAdd);
		// And maybe play a sound effect?
		OnKeyWalletAction.Broadcast(KeyToAdd, EPlayerKeyAction::AddKey, true);
	}
}

void APlayerCPP::RemoveKey(FString KeyToRemove)
{
	if (KeyWallet.Contains(KeyToRemove))
	{
		KeyWallet.Remove(KeyToRemove);
		OnKeyWalletAction.Broadcast(KeyToRemove, EPlayerKeyAction::RemoveKey, true);
	}
	else
	{
		OnKeyWalletAction.Broadcast(KeyToRemove, EPlayerKeyAction::RemoveKey, true);
	}
}

bool APlayerCPP::IsPlayerCarryingKey(FString DesiredKey)
{
	bool Result = KeyWallet.Contains(DesiredKey);
	OnKeyWalletAction.Broadcast(DesiredKey, EPlayerKeyAction::TestKey, Result);
	return Result;
}

void APlayerCPP::InteractCheck()
{
	Cast<APlayerCPPController>(GetController())->GetPlayerViewPoint(ViewVector, ViewRotation);
	FVector VecDirection = ViewRotation.Vector() * 1000.0f;
	FVector InteractEnd = ViewVector + VecDirection;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(InteractHitResult, ViewVector, InteractEnd, ECollisionChannel::ECC_GameTraceChannel1, QueryParams);
}

bool APlayerCPP::Interact()
{
	if (Cast<AMoney>(InteractHitResult.GetActor()))
	{
		if (moneyLimit >= 50000) {
			AMoney* MONEY = Cast<AMoney>(UGameplayStatics::GetActorOfClass(GetWorld(), AMoney::StaticClass()));
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
				*(FString::Printf(TEXT("Money has accumulated to its limit"), KeyWallet.Num())));
			MONEY->Destroy();
			return false;
		}
		else {
			moneyLimit += 1000;
			money += 1000;
			return false;
		};


	}

	if (Cast<AATM>(InteractHitResult.GetActor()))
	{
		return true;
	}

	if (Cast<ATV>(InteractHitResult.GetActor()))
	{
		ATV* TV = Cast<ATV>(UGameplayStatics::GetActorOfClass(GetWorld(), ATV::StaticClass()));
		AATM* ATM = Cast<AATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AATM::StaticClass()));

		if ((ATM->GetMoneyATM()) >= TV->get_price())
		{
			ATM->SetMoneyATM(ATM->GetMoneyATM() - TV->get_price());
			TV->Destroy();
		}

		return false;
	}

	if (Cast<AVisaRegular>(InteractHitResult.GetActor()))
	{
		AVisaRegular* Visa = Cast<AVisaRegular>(UGameplayStatics::GetActorOfClass(GetWorld(), AVisaRegular::StaticClass()));

		AddKey(Visa->GetKeyString());
		Visa->Destroy();
		
		return false;
	}

	if (Cast<AAmericanExpress>(InteractHitResult.GetActor()))
	{
		AAmericanExpress* AmericanExpress = Cast<AAmericanExpress>(UGameplayStatics::GetActorOfClass(GetWorld(), AAmericanExpress::StaticClass()));

		AddKey(AmericanExpress->GetKeyString());
		AmericanExpress->Destroy();

		return false;
	}

	if (Cast<AVisaPrev>(InteractHitResult.GetActor()))
	{
		AVisaPrev* VisaPrev = Cast<AVisaPrev>(UGameplayStatics::GetActorOfClass(GetWorld(), AVisaPrev::StaticClass()));

		AddKey(VisaPrev->GetKeyString());
		VisaPrev->Destroy();

		return false;
	}

	if (Cast<AIndianCard>(InteractHitResult.GetActor()))
	{
		AIndianCard* IndianCard = Cast<AIndianCard>(UGameplayStatics::GetActorOfClass(GetWorld(), AIndianCard::StaticClass()));

		AddKey(IndianCard->GetKeyString());
		IndianCard->Destroy();

		return false;
	}

	else { return false; }
}

int APlayerCPP::GetMoney()
{
	return money;
}

void APlayerCPP::DeductMoney(int deposited)
{
	money = money - deposited;
}