#include "functions.h"

void getScenarioChoice(int* choice)
{
    printf("What do you want to do?\n"
           "1 - Access your workouts\n"
           "2 - Create a new workout\n"
           "3 - View help for excercises\n"
           "0 - Close the app\n"
           "Your choice: ");
    scanf("%d", choice);
}

void restart(int * choice) // функция служит для перезапуска программы
{
    printf("1 - Continue working\n"
           "0 - Close the app\n");
    do {
        printf("Your choice: ");
        scanf("%d", choice);
    } while (*choice != 1 && *choice != 0);
}