#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkTraining.h"

#define MAX_EXERCISES 15
#define GROUPS 3
#define EXERCISES_PER_GROUP (MAX_EXERCISES / GROUPS)

void output(Training workout)
{
    const char *exercise_names[3][5] = {
            {"Приседания","Жим ногами лежа", "Становая тяга", "Болгарские приседания", "Выпады"},
            {"Отжимания", "Жим штанги лёжа", "Жим гантелей",    "Хаммер", "Кроссовер"},
            {"Подтягивания", "Тяга блока","Гребля","Тяга штанги к поясу", "Пулловер"}
    };
    printf("Дата: %s\n "
           "Длительность тренировки: %d\n "
           "Упражнение: %s\n "
           "Повторения: %d\n "
           "Использованный вес: %.1f\n", workout.date, workout.duration, exercise_names[workout.exercise_index[0]][workout.exercise_index[1]], workout.repetitions, workout.weight);
    printf("----------------\n");
}

void read_all_trainings(Training* workouts, int count)
{
    for (int i = 0; i < count; ++i)
        output(workouts[i]);
}

void checkTraining()
{
    Training *workouts = malloc(1*sizeof(Training));
    int count = 0;
    Training temp;

    FILE *file = fopen("training.txt", "r");

    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

    while (fscanf(file, "%10s %d %d %d %d %f", temp.date, &temp.duration, &temp.exercise_index[0], &temp.exercise_index[1], &temp.repetitions, &temp.weight) == 6)
    {
        workouts = realloc(workouts, sizeof(Training) * (count + 1));
        if (workouts == NULL) {
            perror("Error allocating memory");
            fclose(file);
        }
        *(workouts+count) = temp;
        count++;
    }
    fclose(file);

    trainings_toggle(workouts, count);
}

void trainings_toggle(Training* workouts, int count)
{
    int toggle;
    printf("Выберите тип вывода тренировок:\n1-Вывод всех тренировок\n2-Вывод тренировок по дате\n3-Вывод тренировок по упражнению\n");
    scanf("%d", &toggle);
    switch (toggle)
    {
        case 1:
            read_all_trainings(workouts, count);
            break;
        case 2:
        {
            printf("Введите дату тренировки (YYYY-MM-DD): ");
            char date[11];
            scanf("%10s", date);
            printf("\n");
            read_trainings_by_date(date, workouts, count);
            break;
        }
        case 3:
        {
            int group_choice, exercise_choice;
            char *exercise_names[3][5] = {
                    {"Приседания","Жим ногами лежа", "Становая тяга", "Болгарские приседания", "Выпады"},
                    {"Отжимания", "Жим штанги лёжа", "Жим гантелей",    "Хаммер", "Кроссовер"},
                    {"Подтягивания", "Тяга блока","Гребля","Тяга штанги к поясу", "Пулловер"}
                    };

            printf("Выберите группу упражнений (1-3):\n1. Ноги\n2. Грудь\n3. Спина\n");
            scanf("%d", &group_choice);

            if (group_choice < 1 || group_choice > GROUPS)
            {
                printf("Неверный выбор группы упражнений.\n");
                return;
            }

            printf("Выберите упражнение (1-%d):\n", EXERCISES_PER_GROUP);
            for (int i = 0; i < EXERCISES_PER_GROUP; i++)
            {
                if (strlen(exercise_names[group_choice - 1][i]) > 0)
                {
                    printf("%d. %s\n", i + 1, exercise_names[group_choice - 1][i]);
                }
            }
            scanf("%d", &exercise_choice);

            if (exercise_choice < 1 || exercise_choice > EXERCISES_PER_GROUP ||
                strlen(exercise_names[group_choice - 1][exercise_choice - 1]) == 0)
            {
                printf("Неверный выбор упражнения.\n");
                return;
            }

            char *selected_exercise = exercise_names[group_choice - 1][exercise_choice - 1];
            read_trainings_by_exercise(selected_exercise, workouts, count);
            break;
        }
        default:
            printf("Неверный выбор.\n");
            break;
    }
}

void read_trainings_by_date(const char *date, Training *workouts, int count)
{
    for (int i = 0; i < count; ++i)
    {
        if(!strcmp(workouts[i].date, date))
        {
            output(workouts[i]);
        }
    }
}

void read_trainings_by_exercise(const char *exercise, Training *workouts, int count)
{
    const char *exercise_names[3][5] = {
            {"Приседания","Жим ногами лежа", "Становая тяга", "Болгарские приседания", "Выпады"},
            {"Отжимания", "Жим штанги лёжа", "Жим гантелей",    "Хаммер", "Кроссовер"},
            {"Подтягивания", "Тяга блока","Гребля","Тяга штанги к поясу", "Пулловер"}
    };
    for (int i = 0; i < count; ++i)
    {
        if(!strcmp(exercise_names[workouts[i].exercise_index[0]][workouts[i].exercise_index[1]], exercise))
        {
            output(workouts[i]);
        }
    }
}