// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPP.h"

#include "GameFramework/CharacterMovementComponent.h"


//set default values
APlayerCPP::APlayerCPP()
{
	// set this character to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickInterval(0.5f);
	SetActorTickEnabled(true);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> QuinnMesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'"));

	//static ConstructorHelpers::FObjectFinder<UAnimBlueprint> QuinnAnim(TEXT("/Script/Engine.AnimBlueprint'/Game/Characters/Mannequins/Animations/ABP_Quinn.ABP_Quinn'"));

	static ConstructorHelpers::FObjectFinder<USoundWave> CashingAsset(TEXT("/Script/Engine.SoundWave'/Game/SoundEffect/cash_sound.cash_sound'"));

	static ConstructorHelpers::FObjectFinder<USoundWave> CollectingAsset(TEXT("/Script/Engine.SoundWave'/Game/SoundEffect/collect_sound.collect_sound'"));

	static ConstructorHelpers::FObjectFinder<USoundWave> PaperAsset(TEXT("/Script/Engine.SoundWave'/Game/SoundEffect/paper.paper'"));

	if (CashingAsset.Succeeded() && CollectingAsset.Succeeded() && PaperAsset.Succeeded())
	{
		Cashing = CashingAsset.Object;
		Collect = CollectingAsset.Object;
		PickupPaper = PaperAsset.Object;
	}

	UCapsuleComponent* Capsule = GetCapsuleComponent();

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	money = 0;

	if (QuinnMesh.Succeeded())
	{
		//GetMesh()->SetSkeletalMesh(QuinnMesh.Object);
		//GetMesh()->SetAnimInstanceClass(QuinnAnim.Object->GeneratedClass);
		//GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -80.0f));
		//GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

		Capsule->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Capsule->SetCapsuleHalfHeight(90.0f);
		Capsule->SetCapsuleRadius(35.0f);

		Camera->SetupAttachment(GetMesh(), FName("Head"));
		Camera->SetRelativeLocation(FVector(5.0f, 9.0f, 0.0f));
		Camera->SetRelativeRotation(FRotator(0.0f, 90.0f, -90.0f));
		Camera->bUsePawnControlRotation = true;

	}

}


//called when the game starts or when spawned
void APlayerCPP::BeginPlay()
{
	Super::BeginPlay();

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && AnimMontage)
	{
		AnimInstance->Montage_Play(AnimMontage);
	}
	else {
		for (int i = 0; i < 10; i++)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Red,
				TEXT("Error"));
		}
	}

}

 
//called every frame
void APlayerCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Temporarily display debug information
	GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
		*(FString::Printf(TEXT("Keys - %d Keys Currently held"), KeyWallet.Num())));

	InteractCheck();

}

//called to bind functionality to input
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

FString APlayerCPP::Interact()
{
	if (Cast<AMoney>(InteractHitResult.GetActor()))
	{
		if (moneyLimit >= 50000) {
			AMoney* MONEY = Cast<AMoney>(UGameplayStatics::GetActorOfClass(GetWorld(), AMoney::StaticClass()));
			MONEY->Destroy();
			return "false";
		}
		else {
			moneyLimit += 1000;
			money += 1000;

			UGameplayStatics::PlaySound2D(this, Collect);

			return "false";
		}

	}

	if (Cast<AATM>(InteractHitResult.GetActor()))
	{
		return "true";
	}

	if (Cast<ACarSale>(InteractHitResult.GetActor()))
	{
		ACarSale* CarSale = Cast<ACarSale>(UGameplayStatics::GetActorOfClass(GetWorld(), ACarSale::StaticClass()));
		AATM* ATM = Cast<AATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AATM::StaticClass()));

		if ((ATM->GetMoneyATM()) >= CarSale->get_price())
		{
			ATM->DeductMoneyATM(CarSale->get_price());

			UGameplayStatics::PlaySound2D(this, Cashing);

			CarSale->Destroy();
		}

		return "false";
	}

	if (Cast<ARefridgerator>(InteractHitResult.GetActor()))
	{
		ARefridgerator* Refridgerator = Cast<ARefridgerator>(UGameplayStatics::GetActorOfClass(GetWorld(), ARefridgerator::StaticClass()));
		AATM* ATM = Cast<AATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AATM::StaticClass()));

		if ((ATM->GetMoneyATM()) >= Refridgerator->get_price())
		{
			ATM->DeductMoneyATM(Refridgerator->get_price());

			UGameplayStatics::PlaySound2D(this, Cashing);

			Refridgerator->Destroy();
		}

		return "false";
	}



	if (Cast<ATV>(InteractHitResult.GetActor()))
	{
		ATV* TV = Cast<ATV>(UGameplayStatics::GetActorOfClass(GetWorld(), ATV::StaticClass()));
		AATM* ATM = Cast<AATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AATM::StaticClass()));

		if ((ATM->GetMoneyATM()) >= TV->get_price())
		{
			ATM->DeductMoneyATM(TV->get_price());

			UGameplayStatics::PlaySound2D(this, Cashing);

			TV->Destroy();
		}

		return "false";
	}

	if (Cast<AVisaRegular>(InteractHitResult.GetActor()))
	{
		AVisaRegular* Visa = Cast<AVisaRegular>(UGameplayStatics::GetActorOfClass(GetWorld(), AVisaRegular::StaticClass()));

		if (KeyWallet.Num() == 1) {
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
				*(FString::Printf(TEXT("Maximum"))));
		} else {
			AddKey(Visa->GetKeyString());
			Visa->Destroy();
		}
		
		return "false";
	}

	if (Cast<AAmericanExpress>(InteractHitResult.GetActor()))
	{
		AAmericanExpress* AmericanExpress = Cast<AAmericanExpress>(UGameplayStatics::GetActorOfClass(GetWorld(), AAmericanExpress::StaticClass()));

		if (KeyWallet.Num() == 1) {
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
				*(FString::Printf(TEXT("Maximum"))));
		} else {
			AddKey(AmericanExpress->GetKeyString());
			AmericanExpress->Destroy();
		}


		return "false";
	}

	if (Cast<AVisaPrev>(InteractHitResult.GetActor()))
	{
		AVisaPrev* VisaPrev = Cast<AVisaPrev>(UGameplayStatics::GetActorOfClass(GetWorld(), AVisaPrev::StaticClass()));

		if (KeyWallet.Num() == 1) {
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
				*(FString::Printf(TEXT("Maximum"))));
		} else {
			AddKey(VisaPrev->GetKeyString());
			VisaPrev->Destroy();
		}

		return "false";
	}

	if (Cast<AIndianCard>(InteractHitResult.GetActor()))
	{
		AIndianCard* IndianCard = Cast<AIndianCard>(UGameplayStatics::GetActorOfClass(GetWorld(), AIndianCard::StaticClass()));

		if (KeyWallet.Num() == 1) {
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Orange,
				*(FString::Printf(TEXT("Maximum"))));
		} else {
			AddKey(IndianCard->GetKeyString());
			IndianCard->Destroy();
		}

		return "false";
	}

	if (Cast<AAmericanExATM>(InteractHitResult.GetActor()))
	{
		AAmericanExATM* AmericanExATM = Cast<AAmericanExATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AAmericanExATM::StaticClass()));

		if (IsPlayerCarryingKey(AmericanExATM->GetDesiredKey()))
		{
			AmericanExATM->IsSuccess = "Success";
			RemoveKey(AmericanExATM->GetDesiredKey());
		}
		else
		{
			AmericanExATM->IsSuccess = "Fail";
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Red,
				*(FString::Printf(TEXT("Error"))));
		}

		return "false";
	}

	if (Cast<AVisaRegATM>(InteractHitResult.GetActor()))
	{
		AVisaRegATM* VisaRegATM = Cast<AVisaRegATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AVisaRegATM::StaticClass()));
		FTimerHandle UnusedHandle;

		if (IsPlayerCarryingKey(VisaRegATM->GetDesiredKey()))
		{
			VisaRegATM->IsSuccess = "Success";
			RemoveKey(VisaRegATM->GetDesiredKey());
		}
		else
		{
			VisaRegATM->IsSuccess = "Fail";
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Red,
				*(FString::Printf(TEXT("Error"))));
		}

		return "false";
	}

	if (Cast<AVisaPrevATM>(InteractHitResult.GetActor()))
	{
		AVisaPrevATM* VisaPrevATM = Cast<AVisaPrevATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AVisaPrevATM::StaticClass()));

		if (IsPlayerCarryingKey(VisaPrevATM->GetDesiredKey()))
		{
			VisaPrevATM->IsSuccess = "Success";
			RemoveKey(VisaPrevATM->GetDesiredKey());
		}
		else
		{
			VisaPrevATM->IsSuccess = "Fail";
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Red,
				*(FString::Printf(TEXT("Error"))));
		}

		return "false";
	}

	if (Cast<AIndianCardATM>(InteractHitResult.GetActor()))
	{
		AIndianCardATM* IndianCardATM = Cast<AIndianCardATM>(UGameplayStatics::GetActorOfClass(GetWorld(), AIndianCardATM::StaticClass()));

		if (IsPlayerCarryingKey(IndianCardATM->GetDesiredKey()))
		{
			IndianCardATM->IsSuccess = "Success";
			RemoveKey(IndianCardATM->GetDesiredKey());
		}
		else
		{
			IndianCardATM->IsSuccess = "Fail";
			GEngine->AddOnScreenDebugMessage(-1, 0.49f, FColor::Red,
				*(FString::Printf(TEXT("Error"))));
		}

		return "false";
	}

	if (Cast<ANoteObject>(InteractHitResult.GetActor()))
	{
		UGameplayStatics::PlaySound2D(this, PickupPaper);
		return "note";
	}

	else { return "false"; }
}

int APlayerCPP::GetMoney()
{
	return money;
}

void APlayerCPP::DeductMoney(int deposited)
{
	money = money - deposited;
}