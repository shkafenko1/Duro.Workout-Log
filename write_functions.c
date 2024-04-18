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
    char** excercises;
    int type;

    system("clear");
    do{
        printf("Input the date of your workout in format 'DD/MM/YYYY': ");
        scanf("%s", date);
    } while (strlen(date) != 10);
    sscanf(date, "%d.%d.%d", &workout.date[0], &workout.date[1], &workout.date[2]);

    printf("Input the duration of your workout in format 'HH:MM'");
    scanf("%s", time);
    sscanf(time, "%d:%d", &workout.time[0], &workout.time[1]);

    getType(&type);
    excercises = getExcercises();


    return workout;
}

char** getExcercises(int exType)
{
    FILE* list = fopen("excercises_list.txt", "r");
    char excercises[MAX_EXCERCISES][STRING_LENGTH];
    char buffer[STRING_LENGTH];
    int isType = 0;

    while (fgets(buffer, STRING_LENGTH, list) != NULL);

    fclose(list);
    return excercises;
}
