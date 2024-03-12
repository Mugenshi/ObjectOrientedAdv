// Fill out your copyright notice in the Description page of Project Settings.


#include "TextBook.h"

ATextBook::ATextBook()
{
    PrimaryActorTick.bCanEverTick = false;

    Genre = "Text Book";
}

void ATextBook::SetSubject(FString NewSubject)
{
    Subject = NewSubject;
}

void ATextBook::SetEdition(FString NewEdition)
{
    Edition = NewEdition;
}

void ATextBook::SetISBN(FString NewISBN)
{
    ISBN = NewISBN;
}

FString ATextBook::GetSubject() const
{
    return Subject;
}

FString ATextBook::GetEdition() const
{
    return Edition;
}

FString ATextBook::GetISBN() const
{
    return ISBN;
}

FString ATextBook::GetTitle() const
{
    return Title;
}

FString ATextBook::GetAuthor() const
{
    return Author;
}

FString ATextBook::GetContent() const
{
    return Content;
}

FString ATextBook::GetGenre() const
{
    return Genre;
}

void ATextBook::SetGenre(FString NewGenre)
{
    Genre = NewGenre;
}

void ATextBook::SetTitle(FString NewTitle)
{
    Title = NewTitle;
}

void ATextBook::SetAuthor(FString NewAuthor)
{
    Author = NewAuthor;
}

void ATextBook::SetContent(FString NewContent)
{
    Content = NewContent;
}



