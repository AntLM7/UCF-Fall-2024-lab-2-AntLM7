#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generate a random number between 1 and 10
int generate_random_number() {
    return (rand() % 10) + 1;  // Using modulo to keep the number within the range of 1 to 10
}

// user input and validation, making sure the input is within the correct range
int get_guess() {
    int guess;
    while (1) {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) == 1 && guess >= 1 && guess <= 10) {
            return guess;  // If the input is valid, we return it
        } else {
            printf("Invalid input. Please enter a number between 1 and 10.\n");
            // Clear the buffer in case the user enters something invalid
            while (getchar() != '\n');
        }
    }
}

// main function that runs the game logic
void play_game() {
    int random_number = generate_random_number();  // Generate the random number
    int guess;
    int attempts = 3;  // The user gets 3 attempts

    printf("Guess the number (between 1 and 10). You have 3 attempts.\n");

    // Using a loop to give the user multiple chances
    for (int i = 0; i < attempts; i++) {
        guess = get_guess();  // Call the function to get the user's guess

        // use conditional statements to check if the guess is correct, too high, or too low
        if (guess == random_number) {
            printf("Congratulations! You guessed the number.\n");
            return;
        } else if (guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Too low! Try again.\n");
        }

        // let user know how many attempts they have left after each wrong guess
        if (i < attempts - 1) {
            printf("You have %d attempt(s) left.\n", attempts - i - 1);
        }
    }

    // If the user runs out of attempts, reveal the correct number
    printf("Sorry, you've used all your attempts. The number was: %d\n", random_number);
}

int main() {
    srand(time(0));  // Set the random number generator to ensure we get a different number each time

    play_game();  // Start the game by calling the play_game function

    return 0;
}
