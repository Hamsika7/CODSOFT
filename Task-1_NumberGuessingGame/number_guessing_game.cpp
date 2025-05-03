#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int chooseDifficulty() {
    int level, maxNum;
    cout << "\nChoose Difficulty Level:\n";
    cout << "1. Easy (1 - 10)\n";
    cout << "2. Medium (1 - 100)\n";
    cout << "3. Hard (1 - 1000)\n";
    cout << "Enter your choice: ";
    cin >> level;

    switch (level) {
        case 1: maxNum = 10; break;
        case 2: maxNum = 100; break;
        case 3: maxNum = 1000; break;
        default: cout << "Invalid choice! Defaulting to Medium.\n"; maxNum = 100;
    }
    return maxNum;
}

void playGame() {
    srand(time(0));
    int maxNum = chooseDifficulty();
    int number = rand() % maxNum + 1;
    int guess, attempts = 0, maxAttempts = 10;
    vector<int> history;

    cout << "\nYou have " << maxAttempts << " attempts to guess the number!\n";

    while (attempts < maxAttempts) {
        cout << "\nAttempt " << (attempts + 1) << " - Enter your guess: ";
        cin >> guess;
        history.push_back(guess);
        attempts++;

        if (guess == number) {
            cout << "🎉 Correct! You guessed it in " << attempts << " tries.\n";
            cout << "Your Score: " << (100 - attempts * 10) << endl;
            break;
        } else if (guess < number) {
            cout << "Too low!";
        } else {
            cout << "Too high!";
        }

        // Hint system
        if (attempts == 3 || attempts == 5) {
            if (number % 2 == 0)
                cout << " (Hint: It's an even number)";
            else
                cout << " (Hint: It's an odd number)";
        }

        // Show history
        cout << "\nPrevious guesses: ";
        for (int g : history) cout << g << " ";
        cout << endl;
    }

    if (guess != number) {
        cout << "\n💥 You've used all attempts. The number was: " << number << "\n";
    }
}

int main() {
    char playAgain;
    do {
        cout << "\n🎮 Starting New Game...\n";
        playGame();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n👋 Thanks for playing. Goodbye!\n";
    return 0;
}
