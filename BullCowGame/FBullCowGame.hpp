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

class FBullCowGame
{
public:
    void Reset();
    int GetMaxTries();
    int GetCurrentTry();
    void IncreaseTry();
    bool IsGameWon();
    bool CheckGuessValidity(std::string);

private:
    int MyCurrentTry = 1;
    int MyMaxTries = 5;
};

#endif /* FBullCowGame_hpp */
