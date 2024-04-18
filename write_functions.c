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
    FILE* data = fopen("workout_log.txt", "w");
    workoutTemplate workout;

    inputStruct(&workout);
    fprintf(data, "%d/%d/%d\n %d:%d\n %s, %d reps, %d lbs", workout.date[0], workout.date[1], workout.date[2], workout.time[0], workout.time[1], workout.excercises[0], workout.excerciseData[0][0], workout.excerciseData[0][1]);
    fclose(data);
}

void inputStruct(workoutTemplate* workout)
{
    char date[10];
    char time[6];
    char** excercises;
    int type;
    char* temp;

    system("clear");
    do{
        printf("Input the date of your workout in format 'DD/MM/YYYY': ");
        scanf("%s", date);
    } while (strlen(date) != 10);
    sscanf(date, "%d/%d/%d", &(workout->date[0]), &(workout->date[1]), &(workout->date[2]));

    printf("Input the duration of your workout in format 'HH:MM'");
    scanf("%s", time);
    sscanf(time, "%d:%d", &(workout->time[0]), &(workout->time[1]));

    for (int i = 0; i < MAX_EXCERCISES; ++i)
    {
        getType(&type);
        if (type == 0)
            break;
        excercises = getExcercises(&type);
        temp = exChoose(excercises, type);
        strcpy(workout->excercises[i], temp);

        printf("Input the repetitions number: ");
        scanf("%d", &(workout->excerciseData[i][0]));

        printf("Input the weight lifted: ");
        scanf("%d", &(workout->excerciseData[i][1]));
    }
}

char** getExcercises(int* exType)
{
    FILE* list = fopen("excercises_list.txt", "r");
    char** excercises = (char**) malloc(MAX_EXCERCISES * sizeof(char*));
    for (int i = 0; i < MAX_EXCERCISES; ++i)
        *(excercises + i) = (char*) malloc(STRING_LENGTH * sizeof(char));

    char buffer[STRING_LENGTH];
    char* types[] = {"Chest", "Back", "Legs"};
    int count = 0;
    int isType = 0;

    while (fgets(buffer, STRING_LENGTH, list) != NULL)
    {
        if (buffer[0] == '\n')
        {
            isType = 0;
            continue;
        }
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';
        if (!isType)
        {
            if (strcmp(buffer, types[*exType - 1]) == 0)
            {
                isType = 1;
                continue;
            }
        }
        else
        {
            strncpy(excercises[count], buffer, STRING_LENGTH - 1);
            count++;
        }
    }
    fclose(list);
    *exType = count;
    return excercises;
}
