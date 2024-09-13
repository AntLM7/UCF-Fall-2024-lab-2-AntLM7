#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int generate_random_number() {
    return (rand() % 10) + 1;  // Generates a number between 1 and 10
}

// Function to play the guessing game
void play_game() {
    int random_number = generate_random_number();
    int guess;
    int attempts = 3;  // The player has 3 attempts

    printf("Guess the number (between 1 and 10). You have 3 attempts.\n");

    for (int i = 0; i < attempts; i++) {
        printf("Enter your guess: ");
        
        // Check for correct input
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer in case of an invalid input
            while (getchar() != '\n');
            i--;  // Don't count invalid input as an attempt
            continue;
        }

        if (guess == random_number) {
            printf("Congratulations! You guessed the number.\n");
            return;
        } else if (guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Too low! Try again.\n");
        }
    }

    printf("Sorry, you've used all your attempts. The number was: %d\n", random_number);
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Start the game
    play_game();

    return 0;
}

