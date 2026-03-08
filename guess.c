#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); 
    int num = rand() % 21; // gets the random number between 0 and 21-1=20
    int guess;

    while (guess != num)
    {
        printf("Guess the number: ");
        scanf("%d", &guess);
        
        if (guess < num)
        {
            printf("Guessed too low!\n");
        } else if (guess > num){
            printf("Guessed too high!\n");
        }
    }
    
    printf("You guessed right, well done!\n");
    
    return 0;
}