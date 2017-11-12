//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Henrique Nascimento Gouveia on 10/11/17.
//  Copyright © 2017 Onlaraton. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase,
    Invalid_Status
};

class FBullCowGame
{
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;
    size_t GetHiddenWordLength() const;
    
    EGuessStatus CheckGuessValidity(FString) const; // TODO make a more rich return value
    // counts bulls and cows and increases try # assuming valid guess
    FBullCowCount SubmitValidGuess(FString Guess);
    void IncreaseTry();
    void Reset();

private:
    int32 MyCurrentTry = 1;
    int32 MyMaxTries = 5;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    bool IsIsogram(FString) const;
    bool IsLowerCase(FString) const;
};

#endif /* FBullCowGame_hpp */
