#ifndef TRAINING_DIARY_STRUCT_H
#define TRAINING_DIARY_STRUCT_H
typedef struct {
    char date[11]; // Дата тренировки в формате "YYYY-MM-DD"
    int duration;  // Продолжительность тренировки в минутах
    int exercise_index[2]; // Название упражнения
    int repetitions; // Количество повторений
    float weight; // Вес, который использовался
} Training;

extern char *excercise_names[3][5];
#endif
