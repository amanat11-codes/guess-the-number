#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkProgress(int guess, int target, int tries);
void checkGuess(int guess, int target, int progress, int tries);
void makeGuess(int target, int tries);
int get_int(char prompt[]);
int set_difficulty();

int MAX;
char prompt[100];
int main(void)
{
    srand(time(NULL));

    int tries = set_difficulty();

    const int num = rand() % ((tries * 2) + 1); // gets the random number between 0 and 21-1=20
    MAX = num + 15;

    sprintf(prompt, "Guess the number between 0 and %d: ", MAX);
    int guess = get_int(prompt);
    int progress = checkProgress(guess, num, tries);

    checkGuess(guess, num, progress, tries);

    return 0;
}

int checkProgress(int guess, int target, int tries)
{
    // determines the progress of guess, i.e,
    // how far ahead guess deviated from actual num (+ve)
    // or how much it is lagging (-ve)

    int dif = target - guess;

    if (dif >= 5)
    {
        return 1;
    }
    else if ((dif > 0 && dif < 5) || (dif < 0 && dif > -5))
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

void checkGuess(int guess, int target, int progress, int tries)
{
    if (guess == target)
    {
        printf("You guessed right, well done!\n");
        return;
    }
    else if (tries <= 1)
    {
        printf("Game over. The number was %d.\n", target);
        exit(0);
    }
    else
    {
        switch (progress)
        {
        case 1:
            printf("Guessed too low! %d tries left\n", tries - 1);
            break;
        case 2:
            printf("You're close! %d tries left\n", tries - 1);
            break;
        case 3:
            printf("Guessed too high! %d tries left\n", tries - 1);
            break;
        }
        makeGuess(target, tries - 1);
    }
}
void makeGuess(int target, int tries)
{
    int guess = get_int(prompt);
    int progress = checkProgress(guess, target, tries);
    checkGuess(guess, target, progress, tries);
}

int get_int(char prompt[])
{
    int t; // ret = return value of scanf
    int ret = 0;
    while (ret == 0)
    {
        printf("%s", prompt);
        ret = scanf("%d", &t);

        if (ret == EOF)
        {
            puts("\nNo more input, exitting program.");
            exit(0);
        }
        while (getchar() != '\n')
            ;
    }
    return t;
}

int set_difficulty()
{
    printf("Welcome to Guess the Number!\n");
    int difficulty = 0;
    int tries = 0;
    while (!(difficulty >= 1 && difficulty <= 5))
    {
        difficulty = get_int("Difficulty (1 - 5): ");
    }

    return difficulty * 5;
}
