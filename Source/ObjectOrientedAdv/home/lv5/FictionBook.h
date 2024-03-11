// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BookAbstract.h"
#include "FictionBook.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API AFictionBook : public ABookAbstract
{
public:

	AFictionBook();

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	virtual void SetGenre(FString NewGenre) override;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	virtual void SetTitle(FString NewTitle) override;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	virtual void SetAuthor(FString NewAuthor) override;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	virtual void SetContent(FString NewContent) override;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	void SetSpecificGenre(FString NewSpecificGenre);

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetSpecificGenre() const;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	void SetAwards(FString NewAwards);
	
	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetAwards() const;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	void SetCharacters(FString NewCharacters);

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetCharacters() const;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetTitle() const;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetAuthor() const;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetContent() const;

	UFUNCTION(BlueprintCallable, Category = "FictionBook")
	FString GetGenre() const;

private:
	GENERATED_BODY()

	UPROPERTY()
	FString SpecificGenre;

	UPROPERTY()
	FString Awards;

	UPROPERTY()
	FString Characters;
	
};
