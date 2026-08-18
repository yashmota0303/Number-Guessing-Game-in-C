#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
/*advanced guessing game*/
/* under progress*/
/* keep high scores */

/* now add streak boundaries, new powers/life lines ,
time bound, boss battle, save high scores?, trap numbers, */

void blindfold_mode()
{
    /* blindfold mode activated */
        printf("\n\n Blindfold mode activated. Clearing history.\n");
            Sleep(10000); // delay loop
        system("cls");
}

int main()
{
    int  highscore_easy = 20, difficulty, max_attempt;
    int highscore_mid = 12, highscore_hard = 5;
    char play_again = 'y';
    int trap, power_used = 0, lifelines = 0, streak = 0;
    
    srand(time(0)); //random number generator


    while ( play_again == 'y' || play_again == 'Y')
    { 
 
        int secret, guess, attempt = 0, max_number;

        printf("\033[1;36m This is a guessing game. \n");
        printf("Guess between 1 to 25. \033[0m\n\n");
        printf("select difficulty level :");
        printf("\n1. Easy 1 to 10 ( 5 attempts)\n\n2. Medium 1 to 25 (10 attempts)\n\n3. Hard 1 to 100 ( 15 attempts)\n4. BOSS BATTLE\n\n");
        printf("\n\n Enter your choice :");
        scanf("%d", &difficulty);

        if (difficulty ==1)
        {
            max_number = 10;
            max_attempt = 5;
        }
        else if (difficulty == 2)
        {
            max_number = 25;
            max_attempt = 10;
        }
        else if (difficulty == 3)
        {
            max_number = 100;
            max_attempt = 15;
        }

        else if ( difficulty == 4 )
        {
            max_number = 400;
            max_attempt = 25;

            if ( attempt > 0 && attempt % 3 == 0)
            {
                int shift = (rand() % 3 == 0) ? 2 : -2;
                secret += shift;
            }

            if ( secret < 1) secret = 1;
            if ( secret > 400) secret = 400;

            printf("BOSS twist: position is shifted.");
        }
        
        else
        {
            printf("invalid input. Please select a valid difficulty level\n");
            continue;
        }

        secret = rand() % max_number + 1; // num between 1 to 25

        while (difficulty == 3 && trap == secret)
        {
            trap = rand() % max_number + 1;
        }

        if ( secret == trap)
        {
            printf("TRAP TRIGGERED. You have lost 2 attempts\n");
            attempt += 2;
        }
        
        //time

        while (attempt <= max_attempt)
        {
            printf("\nAttempts left: %d |(0 for lifeline) Lifelines left: %d\nEnter your guess :", max_attempt - attempt, lifelines);
            scanf("%d", &guess);

            attempt++;
            
            ///* blindfold mode activated */
            if (difficulty == 3 && attempt % 3 == 0)
            {
                blindfold_mode();
            }

            if ( guess == 0 )
            {
                attempt--;

                if ( lifelines > 0)
                {
                    int choice;
                    printf("---- CHOOSE A LIFELINE ----\n 1. 50/50 cut\n 2. Clamp Range\n 3. Eliminate 3 wrong numbers\n");
                    printf("Select an option :");
                    scanf("%d", &choice);

                    lifelines--;
                    
                    if ( choice == 2) 
                    { 
                        int low = ( secret -5 < 1) ? 1 : secret -5;
                        int high = ( secret + 5 > max_number) ? max_number : secret - 5;
                        printf("LIFELINE activated. range is %d to %d\n", low, high);
                    }

                    else if ( choice == 1 )
                    {
                        int midpoint;
                        midpoint = max_number / 2;
                        if ( secret < midpoint)
                        {
                            printf("Answer is between 1 and %d", midpoint);
                        }

                        else 
                        {
                            printf("Answer is between %d and %d", midpoint + 1, max_number );
                        }

                    }

                    else if ( choice == 3)
                    {
                        int count = 0;
                        printf("ELmination lifeline activated. rule out 3 numbers :");
                        while ( count < 3)
                        {
                            int fake;
                            fake = rand() % max_number + 1;

                            if ( fake != secret && fake != trap)
                            {
                                printf("[%d]", fake);
                                count++;
                            }
                        }
                    }

                    else printf("No lifelines remaining!");
                }

                continue;
            }

            if (guess < 1 || guess > max_number)
            {
                printf("Stay in boundary. Try again.\n");
            }

            else if ( guess == secret)
            {
                printf("That is correct! You took %d attempts", attempt);

                if (difficulty == 1 )
                { 
                    if (attempt < highscore_easy)
                    {
                        highscore_easy = attempt;
                        printf("NEW high score for easy level is %d set by you\n", attempt);
                    }
                
                    else
                    {
                        printf("Current high score for easy level is %d,\n", highscore_easy);
                    }
                }
                
                if (difficulty == 2 )
                {
                    if (attempt < highscore_mid)
                    { 
                        highscore_mid = attempt;
                        printf("NEW high score for medium level is %d set by you\n", attempt);
                    }

                    else
                    {
                        printf("Current high score for medium level is %d,\n", highscore_mid);
                    }
                }    

                if (difficulty == 3 )
                {
                    if (attempt < highscore_hard)
                    { 
                        highscore_hard = attempt;
                        printf("NEW high score for hard level is %d set by you\n", attempt);
                    }

                    else
                    {
                        printf("Current high score for hard level is %d,\n", highscore_hard);
                    }
                }
                
                streak++;
                
                printf("WIN STREAK is %d", streak);

                if ( streak % 3 == 0)
                { 
                    lifelines++;
                    printf("BONUS. You get extra lifeline, total lifeline is %d", lifelines);
                }
                
                break;//end of inner loop
                
            }
            else if (guess < secret)
            {
                printf("Your guess is low. Try again.\n");

                if (guess < secret - 10)
                {
                    printf("Too far\n");
                }
                else if ( difficulty == 3 &&guess < secret - 35)
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
                else if (difficulty == 3 && guess > secret + 35)
                {
                    printf(" seriously far away from the correct answer\n");
                }
            }

            else if ( attempt == max_attempt)
            {
                printf("you have exceeded the limit.Think better\n");
            }

            else if ( guess != secret)
            printf("problem?");

        }

    do 
        {
            attempt = 0;

            printf("\n Do you want to play again?(type y/n) :");
            scanf(" %c", &play_again);

            if (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N')
            {
                printf("invalid input, please type y or n\n");
            }

        } while (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N');

        if (play_again == 'n' || play_again == 'N')
        {
            break;
        }

    }

    printf("Thank you for playing.\n"); 
    printf("HIGHSCORES :\n\n");
    printf("EASY level = %d\n", highscore_easy);
    printf("MEDIUM level = %d\n", highscore_mid);
    printf("HARD level = %d\n", highscore_hard);

    return 0;

}
