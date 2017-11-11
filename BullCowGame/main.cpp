//
//  main.cpp
//  BullCowGame
//
//  Created by Henrique Nascimento Gouveia on 05/11/17.
//  Copyright © 2017 Onlaraton. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main(void) {
    bool bPlayAgain = false;
    
    do {
        BCGame.Reset();
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);
    
    return 0;
}

void PrintIntro() {
    constexpr int WORLD_LEGTH = 9;
    std::cout << "Welcome to Bulls and Cows, a fun game.\n";
    std::cout << "Can you guess the " << WORLD_LEGTH;
    std::cout << " letter isogram I am thinking of?\n";
}

void PlayGame()
{
    int MaxTries = BCGame.GetMaxTries();
    
    for (int count = 1; count <= MaxTries; count++) {
        std::string Guess = GetGuess();
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

std::string GetGuess()
{
    std::cout << "Enter your guess No " << BCGame.GetCurrentTry() << ": ";
    std::string Guess = "";
    std::getline(std::cin, Guess);
    BCGame.IncreaseTry();
    return Guess;
}

bool AskToPlayAgain()
{
    std::string Response = "";
    std::cout << "Would you like to play again [y/n]?\n";
    std::getline(std::cin, Response);
    return ((Response[0] == 'Y') || (Response[0] == 'y'));
}
