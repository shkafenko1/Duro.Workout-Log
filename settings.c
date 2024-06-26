#include "core.h"

void choiceLoop(int* choice, int limit);

void getScenarioChoice(int* choice)
{
    system("clear");
    printf("1 - Access existing workouts\n"
           "2 - Create a new workout\n"
           "3 - View help for excercises\n"
           "0 - Home\n");
    choiceLoop(choice, 3);
}

void accessChoice(int* choice)
{
    system("clear");
    printf("1 - Show all your workouts\n"
           "2 - Show workouts of certain type\n"
           "3 - Show the top workout\n"
           "0 - Home\n");
    choiceLoop(choice, 3);
}

void writeChoice(int* choice)
{
    system("clear");
    printf("1 - Add a new workout\n"
           "0 - Home\n");
    choiceLoop(choice, 1);
}

void getType(int*choice)
{
    printf("Choose the excercise type: \n"
           "1 - Chest\n"
           "2 - Back\n"
           "3 - Legs\n"
           "0 - Home\n");
    choiceLoop(choice, 3);
}



void tipsChoice(int* choice)
{
    system("clear");
    printf("1 - Chest workout\n"
           "2 - Back workout\n"
           "3 - Legs workout\n"
           "0 - Home\n");
    choiceLoop(choice, 3);
}

char* exChoose(char** excercises, int num)
{
    int choice;
    printf("Choose an exercise out of this list:\n");
    for (int i = 0; i < num; ++i)
        printf("%d - %s\n", i + 1, excercises[i]);
    choiceLoop(&choice, num);
    return excercises[choice - 1];
}


















void restart(int * choice) // функция служит для перезапуска программы
{
    system("clear");
    printf("1 - Continue working\n"
           "0 - Close the app\n");
    choiceLoop(choice, 1);
}

void choiceLoop(int * choice, int limit)
{
    do {
        printf("Your choice: ");
        scanf("%d", choice);
    } while (*choice < 0 || *choice > limit);
}


void coolprint()
{
    printf("Under construction!\n");
}