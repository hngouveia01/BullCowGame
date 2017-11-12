/* This is the console executable that make use of the BullCow class
 * this acts as the view in a MVC patter and is responsible for all
 * user interaction. For game logic see the FBullCowGame class.
 */

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main(void)
{    
    bool bPlayAgain = false;
    
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    } while (bPlayAgain);
    
    return 0;
}

void PrintIntro() {
    std::cout << "Welcome to Bulls and Cows, a fun game.\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I am thinking of?\n";
}

void PlayGame()
{
    BCGame.Reset();
    
    int32 MaxTries = BCGame.GetMaxTries();
    
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() < MaxTries) {
        FText Guess = GetValidGuess();
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        std::cout << "Bulls = " << BullCowCount.Bulls << "\n";
        std::cout << "Cows = " << BullCowCount.Cows << "\n";
        std::cout << std::endl;

    }
    
    PrintGameSummary();
}

FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText Guess = "";
    
    do {
        std::cout << "Enter your guess No " << BCGame.GetCurrentTry() << ": ";
        
        std::getline(std::cin, Guess);
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters.\n";
                break;
            case EGuessStatus::OK:
                break;
            case EGuessStatus::Invalid_Status:
                std::cout << "ERROR\n";
                break;
        }
        
        std::cout << std::endl;
        
    } while (Status != EGuessStatus::OK);
    
    BCGame.IncreaseTry();
    return Guess;
}

bool AskToPlayAgain()
{
    FText Response = "";
    std::cout << "Would you like to play again [y/n]?\n";
    std::getline(std::cin, Response);
    return ((Response[0] == 'Y') || (Response[0] == 'y'));
}

void PrintGameSummary()
{
    if (BCGame.IsGameWon()) {
        std::cout << "WELL DONE - YOU WIN!\n";
    } else {
        std::cout << "YOU LOSE!\n";
    }
}
