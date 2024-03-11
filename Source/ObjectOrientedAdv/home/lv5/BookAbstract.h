// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BookAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class OBJECTORIENTEDADV_API ABookAbstract : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	FString Genre;

	UPROPERTY()
	FString Title;

	UPROPERTY()
	FString Author;

	UPROPERTY()
	FString Content;


public:	
	// Sets default values for this actor's properties
	ABookAbstract();

	// Setters
	virtual void SetGenre(FString NewGenre) PURE_VIRTUAL(ABookAbstract::SetGenre, );

	virtual void SetTitle(FString NewTitle) PURE_VIRTUAL(ABookAbstract::SetTitle, );

	virtual void SetAuthor(FString NewAuthor) PURE_VIRTUAL(ABookAbstract::SetAuthor, );

	virtual void SetContent(FString NewContent) PURE_VIRTUAL(ABookAbstract::SetContent, );

};
