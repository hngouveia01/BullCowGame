//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Henrique Nascimento Gouveia on 10/11/17.
//  Copyright © 2017 Onlaraton. All rights reserved.
//

#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    bGameIsWon = false;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::IncreaseTry()
{
    MyCurrentTry++;
}

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FText Guess) const
{
    if (false) { // if it is not isogram
        return EGuessStatus::Not_Isogram;
    } else if (false) { // if it is not lower_case
        return EGuessStatus::Not_Lowercase;
    } else if (Guess.length() != GetHiddenWordLength()) { // if the guess length is wrong
        return EGuessStatus::Wrong_Length;
    }
    
    return EGuessStatus::OK; // TODO make actual error
}

size_t FBullCowGame:: GetHiddenWordLength() const { return MyHiddenWord.length(); }

FBullCowGame::FBullCowGame()
{
    Reset();
}

// receives a VALID guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    FBullCowCount BullCowCount;
    
    size_t WordLength = MyHiddenWord.length();
    
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
        for (int32 GChar = 0; GChar < WordLength; GChar++) {
            if (Guess[GChar] == MyHiddenWord[MHWChar]) {
                if (MHWChar == GChar) {
                    BullCowCount.Bulls++;
                } else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    if (BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    } else {
        bGameIsWon = false;
    }
    
    return BullCowCount;
}


