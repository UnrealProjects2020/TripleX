#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " Swiss Bank Master Account.\n";
    std::cout << "Enter the correct code before secure guard finds out!...\n\n";

}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print CodeSum and CodeProduct to the terminal
    std::cout << "> There are 3 numbers in the code.";
    std::cout << "\n> The codes add-up to: " << CodeSum;
    std::cout << "\n> The codes multiply to give: " << CodeProduct;

    std::cout << "\n\nType your code here, you have 30 seconds: \n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check player answers
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You have entered correct code, $1000 received, now moving on to the next level where more money awaits.***\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You've lost, now try again before anyone finds out!***\n";
        return false;
    }
}

int main()
{   
    srand(time(NULL)); // Create new seeds for rand based on the time

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errorsq
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "Congratulation!! You have completed all levels and earned $999999999 !!";

    return 0;
}