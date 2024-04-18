#define MAX_EXCERCISES 50
#define STRING_LENGTH 80

typedef struct
{
    int date[3];
    int time;
    char excercises[MAX_EXCERCISES][STRING_LENGTH];
    int excerciseData[MAX_EXCERCISES][2]; // 1st element is num of reps and the 2nd one is weight
}workoutTemplate;