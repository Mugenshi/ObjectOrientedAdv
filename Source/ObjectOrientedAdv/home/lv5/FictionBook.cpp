// Fill out your copyright notice in the Description page of Project Settings.


#include "FictionBook.h"

AFictionBook::AFictionBook()
{
    PrimaryActorTick.bCanEverTick = false;

    Genre = "Fiction";
}

void AFictionBook::SetGenre(FString NewGenre)
{
    Genre = NewGenre;
}

void AFictionBook::SetTitle(FString NewTitle)
{
    Title = NewTitle;
}

void AFictionBook::SetAuthor(FString NewAuthor)
{
    Author = NewAuthor;
}

void AFictionBook::SetContent(FString NewContent)
{
    Content = NewContent;
}

void AFictionBook::SetSpecificGenre(FString NewSpecificGenre)
{
    SpecificGenre = NewSpecificGenre;
}

void AFictionBook::SetAwards(FString NewAwards)
{
    Awards = NewAwards;
}

void AFictionBook::SetCharacters(FString NewCharacters)
{
    Characters = NewCharacters;
}

FString AFictionBook::GetTitle() const
{
    return Title;
}

FString AFictionBook::GetAuthor() const
{
    return Author;
}

FString AFictionBook::GetContent() const
{
    return Content;
}

FString AFictionBook::GetGenre() const
{
    return Genre;
}

FString AFictionBook::GetSpecificGenre() const
{
    return SpecificGenre;
}

FString AFictionBook::GetAwards() const
{
    return Awards;
}

FString AFictionBook::GetCharacters() const
{
    return Characters;
}

