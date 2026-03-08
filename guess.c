#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkProgress(int guess, int target);
void checkGuess(int guess, int target, int progress);
void makeGuess(int target);
int get_guess(char prompt[]);

int main(void)
{
    srand(time(NULL)); 
    const int num = rand() % 21; // gets the random number between 0 and 21-1=20
    int guess = get_guess("Guess the number: ");
    int progress = checkProgress(guess, num);
   
    //printf("Guess the number: ");
    //scanf("%d", &guess);
    
    checkGuess(guess, num, progress);
    

    return 0;
}

int checkProgress(int guess, int target)
{
    // determines the progress of guess, i.e,
    // how far ahead guess deviated from actual num (+ve)
    // or how much it is lagging (-ve)
    
    int dif = target - guess;

    if (dif >= 5)
    {
        return 1; 
    } else if ((dif > 0 && dif < 5) || (dif < 0 && dif > -5)){
        return 2; 
    } else {
        return 3;
    }
}

void checkGuess(int guess, int target, int progress)
{
    if (guess == target)
    {
        printf ("You guessed right, well done!\n");
        return;
    }
    if (guess != target)
    {
        switch (progress)
        {
            case 1:
                printf("Guessed too low!\n");
                break;
            case 2:
                printf("You're close!\n");
                break;
            case 3:
                printf("Guessed too high!\n");
                break;
        }
        makeGuess(target);
    }
}
void makeGuess(int target)
{
    int guess = get_guess("Guess the number: ");
    int progress = checkProgress(guess, target);
    checkGuess(guess, target, progress);
}

int get_guess(char prompt[])
{
    int t; // ret = return value of scanf  
    int ret = 0;
    while(ret == 0)
    {
        printf("%s", prompt);
        ret = scanf("%d",&t);

        if (ret == EOF){
            puts("\nNo more input, exitting program.");
            exit(0);
        }    
        while(getchar()!='\n');
    }

    return t;
}