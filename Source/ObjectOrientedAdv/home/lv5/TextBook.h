// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BookAbstract.h"
#include "TextBook.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTORIENTEDADV_API ATextBook : public ABookAbstract
{
	GENERATED_BODY()

public:

	ATextBook();

	// Setters
	UFUNCTION(BlueprintCallable, Category = "TextBook")
	virtual void SetGenre(FString NewGenre) override;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	virtual void SetTitle(FString NewTitle) override;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	virtual void SetAuthor(FString NewAuthor) override;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	virtual void SetContent(FString NewContent) override;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	void SetSubject(FString NewSubject);

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	void SetEdition(FString NewEdition);

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	void SetISBN(FString NewISBN);

	// Getters
	UFUNCTION(BlueprintCallable, Category = "TextBook")
	FString GetSubject() const;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	FString GetEdition() const;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	FString GetISBN() const;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	FString GetTitle() const;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	virtual FString GetAuthor() const;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	virtual FString GetContent() const;

	UFUNCTION(BlueprintCallable, Category = "TextBook")
	FString GetGenre() const;

private:

	UPROPERTY()
	FString Subject;

	UPROPERTY()
	FString Edition;

	UPROPERTY()
	FString ISBN;	
	
};
