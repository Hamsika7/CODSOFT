#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower, upper;      // Range boundaries
    int target, guess;     // Random number and user's guess
    int attempts = 0;      // To count number of attempts

    // Ask the user to enter the desired range
    printf("Enter the lower and upper limits for the number: ");
    scanf("%d %d", &lower, &upper);

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate a random number in the user-defined range
    target = rand() % (upper - lower + 1) + lower;

    // Welcome message
    printf("🎯 Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between %d and %d.\n", lower, upper);
    printf("Can you guess it?\n");

    // Infinite loop until the correct guess is made
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        // Give feedback based on the guess
        if (guess > target)
            printf("TOO HIGH 🔺\nTry again...\n");
        else if (guess < target)
            printf("TOO LOW 🔻\nTry again...\n");
        else {
            // Correct guess
            printf("🎉 CONGRATULATIONS! You guessed it in %d attempts.\n", attempts);
            break;
        }
    }

    return 0;
}

