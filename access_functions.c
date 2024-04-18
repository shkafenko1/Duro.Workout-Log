#include "core.h"
#include "access_functions.h"

void accessWorkouts()
{
    int choice;
    accessChoice(&choice);

    switch (choice)
    {
        case 1:
            allWorkouts();
            break;
        case 2:
            pickByCertainExcercise();
            break;
        case 3:
            findBest();
            break;
        default:
            break;
    }
}

void allWorkouts()
{
    coolprint();
}

void pickByCertainExcercise()
{
    coolprint();
}

void findBest()
{
    coolprint();
}