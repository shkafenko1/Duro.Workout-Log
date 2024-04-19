#include "core.h"
#include "access_functions.h"

void accessWorkouts()
{
    workoutTemplate* workouts = NULL;
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
    free(workouts);
}

void allWorkouts()
{
    workoutTemplate* workouts;
    int size = 1;
    char cnt;
    char read[STRING_LENGTH];
    int offset = 0;
    int numValues = 0;
    int numScanned;

    FILE* data = fopen("workout_log.txt", "r");

    while ((cnt = fgetc(data)) != EOF)
        if (cnt == '\n')
            size++;

    rewind(data);

    workouts = (workoutTemplate*) malloc(size * sizeof(workoutTemplate));

    for (int i = 0; i < size; ++i)
    {
        fgets(read, STRING_LENGTH + 1, data);

        sscanf(read, "%d/%d/%d %d:%d", &workouts[i].date[0], &workouts[i].date[1], &workouts[i].date[3], &workouts[i].time[0], &workouts[i].time[1]);
        while (sscanf(offset + read, "%s, %d reps, %d kgs;", workouts[i].excercises[numValues], &workouts[i].excerciseData[numValues][0], &workouts[i].excerciseData[numValues][1]) == 4)
        {
                numValues++;
                numScanned = sscanf(offset + read, "%s, %d reps, %d kgs;", workouts[i].excercises[numValues], &workouts[i].excerciseData[numValues][0], &workouts[i].excerciseData[numValues][1]);
                offset += numScanned;
        }
    }

    printf("%s", workouts[0].excercises[0]);
    printf("%s", workouts[1].excercises[0]);


    free(workouts);
}

void pickByCertainExcercise()
{
    coolprint();
}

void findBest()
{
    coolprint();
}