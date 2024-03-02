// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetCPPBase.h"
#include "DefaultLayout.generated.h"

class UImage;

/**
 * 
 */
UCLASS(Abstract)
class OBJECTORIENTEDADV_API UDefaultLayout : public UWidgetCPPBase
{
public:
	UPROPERTY(BlueprintReadOnly, Category = "Constituent Controls", meta = (BindWidget))
	TObjectPtr<UImage> Image;

private:
	GENERATED_BODY()
	
};
