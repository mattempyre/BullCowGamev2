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

  
    // Check if Isogram
    // Prompt To Guess Again
    // Check if right number of charcters
    // Prompt To Guess Again
    
    // Remove Life

    // Check if Lives > O
    // If Yes GuessAgain
    // Show Lives Left
    // If No Show GameOver and HiddenWord?
    // Prompt to Play again, Press Enter To Play Again?
    // Check User Input
    // PlayAgain or Quit
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
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again"));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
if (Guess == HiddenWord)
        {
            PrintLine(TEXT("You Have Won!"));
            EndGame();
        }
        else
        {
            
            PrintLine(TEXT("You've lost a life"));
            PrintLine(TEXT("%i"), --Lives);
            
            if (Lives > 0)
            {
                 if (Guess.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining"), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("You have no lives left"));
                EndGame();
            }
        }
}