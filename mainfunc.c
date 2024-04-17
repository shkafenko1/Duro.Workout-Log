#include "functions.h"

void aloe(int* choice)
{
    printf("What do you want to do?\n"
           "1 - access your workouts\n"
           "2 - create a new workout\n"
           "3 - view help for excercises\n"
           "0 - close the app\n"
           "Your choice: ");
    scanf("%d", choice);
}