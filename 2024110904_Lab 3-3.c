#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

int goal_num;

void game(int guess)
{   static int guess_time = 1;
    if (guess == goal_num) printf("Correct!\nguess_time: %d", guess_time);
    else
    {   if (guess_time == 6) printf("You lose!\nGuess_time has exceeded 6.\nThe answer is %d", goal_num);
        else
        {   if (guess > goal_num) printf("Bigger than the answer, guess again: ");
            else printf("Smaller than the answer, guess again: ");

            guess_time++;
            int guess0 = 0;
            scanf("%d", &guess0);
            game(guess0);
        }
    }
}

int main()
{   srand(time(0));
    goal_num = rand() % 100 + 1;
    printf("A random number has been generated between 1 and 100.\nGuess the number: ");

    int guess = 0;
    scanf("%d", &guess);
    game(guess);
    return 0;
}