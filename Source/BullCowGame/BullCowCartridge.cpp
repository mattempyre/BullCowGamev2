// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking PlayerGuess
    {
        ProcessGuess(Input);
        
    }
    // if game is over then do ClearScreen() and SetupGame() the game
    // else Checking Player Guess

  

}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to the Bull and Cows Game"));
    
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess. \nPress ENTER to continue"));    

    // const TCHAR HW[] = TEXT("cakes");
    // PrintLine(TEXT("Character 1 of the hidden word is: %c"), HW[0]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("\nPress enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You Have Won!"));
        EndGame();
        return;
    }

    
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        return;
    }

    // Check if Isogram
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    // Remove Life
    PrintLine(TEXT("You've lost a life"));
    --Lives;
    // Check if Lives > O
    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left"));
        PrintLine(TEXT("The Hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
    // Show Lives Left
    // If No Show GameOver and HiddenWord?
    // Prompt to Play again, Press Enter To Play Again?
    // Check User Input
    // PlayAgain or Quit
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
    // For each letter
    // Start at Element [0]
    // Compare against the next letter.
    // Until we reach [Word.Len() -1]
    // if any letters are the same return false

    return true;
}