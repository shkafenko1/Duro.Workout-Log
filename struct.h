#define MAX_EXCERCISES 10
#define STRING_LENGTH 80

typedef struct
{
    int date[3]; // DD/MM/YYYY of the workout
    int time; // duration of the workout
    char excercises[MAX_EXCERCISES][STRING_LENGTH]; // array of excercises names
    int excerciseData[MAX_EXCERCISES][2]; // 1st element is num of reps and the 2nd one is weight
}workoutTemplate;