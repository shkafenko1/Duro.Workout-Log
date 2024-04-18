#include "core.h"
#include "write_functions.h"

void recordNewWorkout()
{
    int choice;
    writeChoice(&choice);

    if(choice == 1)
    {
        writeNew();
    }
}

void writeNew()
{
    workoutTemplate inpWorkout;

    inpWorkout = inputStruct();
}

workoutTemplate inputStruct()
{
    workoutTemplate workout;
    char date[10];
    char time[6];

    do{
        printf("Input the date of your workout in format 'DD/MM/YYYY: '");
        scanf("%s", date);
    } while (strlen(date) != 10);
    sscanf(date, "%d.%d.%d", &workout.date[0], &workout.date[1], &workout.date[2]);

    printf("Input the duration of your workout in format 'XX:XX'");
    scanf("%s", time);
    sscanf(time, "%d:%d", &workout.time[0], &workout.time[1]);




    return workout;
}