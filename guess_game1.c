#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess,attempt = 0, secret, number;
    
    srand(time(0)); //random number generator

    secret = rand() % 25 + 1; // num between 1 to 25

    printf("\033[1;36m This is a guessing game. \n");
    printf("Guess between 1 to 25. \033[0m \n");

    while (attempt <= 10)
    {
        printf("Enter your guess :");
        scanf("%d", &guess);
        attempt++;

        if ( guess == secret)
        {
            printf("That is correct! You took %d attempts", attempt);
            break;
        }
        else if (guess < secret)
        {
            printf("Your guess is low. Try again.\n");

            if (guess < secret - 10)
            {
                printf("Too far\n");
            }
            else if (guess < secret - 35)
            {
                printf(" seriously far from the correct answer\n");
            }
        }

        else if (guess > secret)
        {
            printf("Your guess is high. Try again.\n");
            
            if (guess > secret + 10)
            { 
                printf(" Too far\n");
            }
            else if (guess > secret + 35)
            {
                printf(" seriously far away from the correct answer\n");
            }
        }

        else if (guess < 1 || guess > 25)
        {
            printf("invalid guess. Try again.\n");
        }

        else if ( guess < secret - 85 || guess > secret + 85)
        {
            printf("answer is at other end of the world.\n");
        }

        else if ( attempt == 35)
        {
            printf("you have exceeded the limit.Think better\n");
        }
    }
 return 0;
} 