// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetCPPBase.h"
#include "CreditCardNote.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API UCreditCardNote : public UWidgetCPPBase
{
private:
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UTextBlock> note_text;
	
};
