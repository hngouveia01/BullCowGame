//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Henrique Nascimento Gouveia on 10/11/17.
//  Copyright © 2017 Onlaraton. All rights reserved.
//

#include "FBullCowGame.hpp"

void FBullCowGame::Reset()
{
    MyCurrentTry = 1;
}

int FBullCowGame::GetMaxTries()
{
    return MyMaxTries;
}

int FBullCowGame::GetCurrentTry()
{
    return MyCurrentTry;
}

void FBullCowGame::IncreaseTry()
{
    MyCurrentTry++;
}

bool FBullCowGame::IsGameWon()
{
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string Guess)
{
    return false;
}
