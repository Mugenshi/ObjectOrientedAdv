// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetCPPBase.h"
#include "ObjectOrientedAdv/player/objects/ATM.h"
#include "Kismet/GameplayStatics.h"
#include "ATMWidget.generated.h"

class UTextBlock;
class UImage;
class UButton;
class AATM;

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API UATMWidget : public UWidgetCPPBase
{
public:

	UFUNCTION(BlueprintCallable, Category = "Constituent Controls")
	FText GetMoneyText();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UImage> Image;

private:
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<AATM> ATM;
	
};
