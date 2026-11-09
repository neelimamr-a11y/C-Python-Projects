#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice,difficulty,range,attempts,secret,guess, i,won,score,highScore = 0;
    char playAgain;
    srand(time(0));
    while(1)
    {
        printf("\n=================================\n");
        printf("       NUMBER GUESSING GAME\n");
        printf("=================================\n");

        printf("1. Start Game\n");
        printf("2. Instructions\n");
        printf("3. View High Score\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            playAgain = 'Y';
            while(playAgain == 'Y' || playAgain == 'y')
            {
                printf("\n1. Easy    Range=1-50   Attempts=10 \n");
                printf("2. Medium  Range=1-100  Attempts=7 \n");
                printf("3. Hard    Range=1-500  Attempts=5 \n");
                printf("\nEnter difficulty: ");
                scanf("%d", &difficulty);
                if(difficulty == 1)
                {
                    range = 50;
                    attempts = 10;
                }
                else if(difficulty == 2)
                {
                    range = 100;
                    attempts = 7;
                }
                else if(difficulty == 3)
                {
                    range = 500;
                    attempts = 5;
                }
                else
                {
                    printf("\nInvalid difficulty! Please enter 1, 2 or 3.\n");
                    continue;
                }

                secret = rand() % range + 1;
                won = 0;
                for(i = 1; i <= attempts; i++)
                {
                    printf("\nAttempt %d/%d", i, attempts);
                    printf("\nEnter your guess: ");
                    scanf("%d", &guess);
                    if(guess < 1 || guess > range)
                    {
                        printf("Invalid guess! Enter a number between 1 and %d.\n",
                               range);
                        i--;
                        continue;
                    }
                    if(guess == secret)
                    {
                        score = 100 - (i - 1) * 10;
                        printf("\n================================\n");
                        printf("          YOU WIN!\n");
                        printf("================================\n");
                        printf("\nYou guessed the number correctly!\n");
                        printf("Attempts Used : %d\n", i);
                        printf("Score         : %d\n", score);

                        printf("\nCongratulations!\n");
                        won = 1;
                        if(score > highScore)
                        {
                            highScore = score;
                        }
                        break;
                    }
                    else if(guess - secret <= 5 &&
                            guess - secret >= -5)
                    {
                        printf("Very Close!\n");
                    }
                    else if(guess > secret)
                    {
                        printf("Too High!\n");
                    }
                    else
                    {
                        printf("Too Low!\n");
                    }
                }

                if(won == 0)
                {
                    printf("\n================================\n");
                    printf("          GAME OVER\n");
                    printf("================================\n");
                    printf("\nYou have used all your attempts.\n");
                    printf("The secret number was: %d\n", secret);
                    printf("Better luck next time!\n");
                }

                printf("\nDo you want to play again? (Y/N): ");
                scanf(" %c", &playAgain);
                while(playAgain != 'Y' && playAgain != 'y' &&
                      playAgain != 'N' && playAgain != 'n')
                {
                    printf("Invalid choice! Enter Y or N: ");
                    scanf(" %c", &playAgain);
                }
            }
        }

        else if(choice == 2)
        {
            printf("\n=================================\n");
            printf("          INSTRUCTIONS\n");
            printf("=================================\n");
            printf("\n1. Select a difficulty level.");
            printf("\n\n 1.Easy");
            printf("\nRange    : 1 - 50");
            printf("\nAttempts : 10");
            printf("\n\n 2.Medium");
            printf("\nRange    : 1 - 100");
            printf("\nAttempts : 7");
            printf("\n\n 3.Hard");
            printf("\nRange    : 1 - 500");
            printf("\nAttempts : 5");
            printf("\n\n2. The computer randomly selects a secret number.");
            printf("\n3. Enter your guess within the selected range.");
            printf("\n4. If your guess is greater than the secret number,");
            printf("\n   you will get 'Too High!'.");
            printf("\n5. If your guess is smaller than the secret number,");
            printf("\n   you will get 'Too Low!'.");
            printf("\n6. If your guess is very close to the secret number,");
            printf("\n   you will get 'Very Close!'.");
            printf("\n7. Guess the number correctly before you run out");
            printf("\n   of attempts to win the game.");
            printf("\n8. Your score depends on the number of attempts used.");
            printf("\n9. You can choose to play again after completing");
            printf("\n   a game.\n");
        }
        else if(choice == 3)
        {
            printf("\n================================\n");
            printf("          HIGH SCORE\n");
            printf("================================\n");
            printf("\nHighest Score : %d\n", highScore);
        }

        else if(choice == 4)
        {
            printf("\nThank you for playing!\n");
            break;
        }

        else
        {
            printf("\nInvalid choice! Please enter 1, 2, 3 or 4.\n");
        }
    }

    return 0;
}
