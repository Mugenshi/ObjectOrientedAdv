// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetCPPBase.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API UWidgetCPPBase : public UUserWidget
{
public:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif


private:
	GENERATED_BODY()
	
};
