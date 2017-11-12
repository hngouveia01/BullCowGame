#include <map>
#include <string>
#include "FBullCowGame.hpp"

#define TMap std::map

using FText = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 3;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    bGameIsWon = false;
}

int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries {{3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20}};
    return WordLengthToMaxTries[MyHiddenWord.length()];
    
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::IncreaseTry()
{
    MyCurrentTry++;
}

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FText Guess) const
{
    if (!IsIsogram(Guess)) { // if it is not isogram
        return EGuessStatus::Not_Isogram;
    }
    
    if (!IsLowerCase(Guess)) { // if it is not lower_case
        return EGuessStatus::Not_Lowercase;
    }
    
    if (Guess.length() != GetHiddenWordLength()) { // if the guess length is wrong
        return EGuessStatus::Wrong_Length;
    }
    
    return EGuessStatus::OK;
}

size_t FBullCowGame:: GetHiddenWordLength() const { return MyHiddenWord.length(); }

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

bool FBullCowGame::IsIsogram(FString Word) const
{
    // treat 0 and 1 letter words as isograms
    if (Word.length() <= 1) {
        return true;
    }
    
    TMap<char, bool> LetterSeen;
    for (auto Letter : Word) {
        Letter = tolower(Letter);
        if (LetterSeen[Letter]) {
            return false;
        } else {
            LetterSeen[Letter] = true;
        }
    }
    return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
    for (auto Letter : Word) {
        if (!islower(Letter)) {
            return false;
        }
    }
    
    return true;
}




