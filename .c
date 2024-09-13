#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 10
int generate_random_number() {
    return (rand() % 10) + 1;
}

// Function to play the guessing game
void play_game() {
    int random_number = generate_random_number();
    int guess, attempts = 3;

    printf("Guess the number (between 1 and 10). You have 3 attempts.\n");

    for (int i = 0; i < attempts; i++) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

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
    // Initialize random number generator
    srand(time(0));

    // Start the game
    play_game();

    return 0;
}
