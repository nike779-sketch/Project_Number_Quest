
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to play the game
void playGame()
{
    int choice;
    int secretNumber;
    int guess;
    int attempts = 0;
    int maxAttempts;
    int maxNumber;
    int score = 0;

    printf("\n===== SELECT DIFFICULTY =====\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Select difficulty
    switch(choice)
    {
        case 1:
            maxNumber = 10;
            maxAttempts = 5;
            printf("\nYou selected EASY mode!\n");
            break;

        case 2:
            maxNumber = 50;
            maxAttempts = 7;
            printf("\nYou selected MEDIUM mode!\n");
            break;

        case 3:
            maxNumber = 100;
            maxAttempts = 10;
            printf("\nYou selected HARD mode!\n");
            break;

        default:
            printf("\nInvalid choice! Starting Easy mode.\n");
            maxNumber = 10;
            maxAttempts = 5;
    }

    // Generate random number
    secretNumber = rand() % maxNumber + 1;

    printf("\nI have selected a number between 1 and %d.\n", maxNumber);
    printf("You have %d attempts to guess it.\n", maxAttempts);

    // Guessing loop
    while(attempts < maxAttempts)
    {
        printf("\nEnter your guess: ");

        if(scanf("%d", &guess) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            int ch;
            while((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        if(guess < 1 || guess > maxNumber)
        {
            printf("Please enter a number between 1 and %d.\n", maxNumber);
            continue;
        }

        attempts++;

        if(guess == secretNumber)
        {
            printf("\nCongratulations! You guessed correctly!\n");
            printf("The secret number was %d.\n", secretNumber);

            score = (maxAttempts - attempts + 1) * 10;

            printf("Attempts used: %d\n", attempts);
            printf("Your score: %d\n", score);

            break;
        }

        else if(guess < secretNumber)
        {
            printf("Too low! Try a higher number.\n");
        }

        else
        {
            printf("Too high! Try a lower number.\n");
        }

        printf("Attempts remaining: %d\n", maxAttempts - attempts);
    }

    // Check if player lost
    if(guess != secretNumber && attempts >= maxAttempts)
    {
        printf("\nGAME OVER!\n");
        printf("The correct number was %d.\n", secretNumber);
        printf("Your score: 0\n");
    }
}

// Main function
int main()
{
    char playAgain;

    // Initialize random number generator
    srand(time(0));

    printf("================================\n");
    printf("       NUMBER QUEST GAME\n");
    printf("================================\n");

    do
    {
        playGame();

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'Y' || playAgain == 'y');

    printf("\nThank you for playing NUMBER QUEST!\n");

    return 0;
}
