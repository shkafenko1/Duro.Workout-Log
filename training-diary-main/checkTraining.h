#ifndef TRAINING_DIARY_CHECKTRAINING_H
#define TRAINING_DIARY_CHECKTRAINING_H
#include "struct.h"
void checkTraining();
void trainings_toggle(Training* workouts, int count);
void read_trainings_by_date(const char *date, Training *workouts, int count);
void read_trainings_by_exercise(const char *exercise, Training *workouts, int count);
#endif