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
    FILE* data = fopen("workout_log.txt", "a");
    workoutTemplate workout;
    int counter;

    inputStruct(&workout, &counter);

    fprintf(data, "\n%d/%d/%d %d:%d", workout.date[0], workout.date[1], workout.date[2], workout.time[0], workout.time[1]);
    for (int i = 0; i < counter; ++i)
        fprintf(data, " %s, %d reps, %d kgs", workout.excercises[i], workout.excerciseData[i][0], workout.excerciseData[i][1]);

    fclose(data);
}

void inputStruct(workoutTemplate* workout, int* num)
{
    char** excercises;
    int type;
    char* temp;

    system("clear");

    printf("Input the date of your workout in format 'DD MM YYYY': ");
    for (int i = 0; i < 3; ++i)
        scanf("%d", &(workout->date[i]));

    printf("Input the duration of your workout in format 'HH MM'");
    for (int i = 0; i < 2; ++i)
        scanf("%d", &(workout->time[i]));

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
        (*num)++;
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
