// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetCPPBase.h"
#include "ObjectOrientedAdv/player/character/PlayerCPP.h"
#include "Kismet/GameplayStatics.h"
#include "DefaultLayout.generated.h"

class UImage;
class UTextBlock;
class APlayerCPP;

/**
 * 
 */
UCLASS(Abstract)
class OBJECTORIENTEDADV_API UDefaultLayout : public UWidgetCPPBase
{
public:

	UFUNCTION(BlueprintCallable, Category = "Constituent Controls")
	FText GetMoneyText();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UImage> Image;

	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UTextBlock> money_text;


private:
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<APlayerCPP> PlayerCharacter;
	
};
