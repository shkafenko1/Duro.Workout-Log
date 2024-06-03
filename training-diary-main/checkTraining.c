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
            read_trainings_by_date(date);
            break;
        }
        case 3:
        {
            int group_choice, exercise_choice;
            const char *exercise_names[3][5] = {
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
            read_trainings_by_exercise(selected_exercise);
            break;
        }
        default:
            printf("Неверный выбор.\n");
            break;
    }
}

/*void read_trainings_by_date(const char *date)
{
    FILE *file = fopen("training.txt", "r");
    if (!file)
    {
        perror("Не удалось открыть файл");
        return;
    }

    char line[256];
    int match = 0; // Флаг для вывода тренировки

    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "Дата: ", 6) == 0)
        {
            if (strstr(line, date))
            {
                match = 1;
            } else {
                match = 0;
            }
        }
        if (match)
        {
            printf("%s", line);
        }
    }

    fclose(file);
}

void read_trainings_by_exercise(const char *exercise)
{
    FILE *file = fopen("training.txt", "r");
    if (!file)
    {
        perror("Не удалось открыть файл");
        return;
    }

    char line[80];
    int match = 0; // Флаг для вывода тренировки

    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "Упражнение: ", 12) == 0)
        {
            if (strstr(line, exercise))
            {
                fseek(file, -3*(long) strlen(line), SEEK_CUR);
                for (int i = 0; i < 6; ++i)
                {
                    fgets(line, sizeof(line), file);
                    printf("%s", line);
                }
                break;
*/
/*                match = 1;
            } else
            {
                match = 0;*//*

            }
        }
*/
/*        if (match)
        {
            printf("%s", line);
        }*//*

    }

    fclose(file);
}

void checkTraining()
{
    int choice;

    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            read_all_trainings();
            break;
        case 2:
        {
            printf("Введите дату тренировки (YYYY-MM-DD): ");
            char date[11];
            scanf("%10s", date);
            printf("\n");
            read_trainings_by_date(date);
            break;
        }
        case 3:
        {
            int group_choice, exercise_choice;
            char *exercises[GROUPS][EXERCISES_PER_GROUP] =
                    {
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
                if (strlen(exercises[group_choice - 1][i]) > 0)
                {
                    printf("%d. %s\n", i + 1, exercises[group_choice - 1][i]);
                }
            }
            scanf("%d", &exercise_choice);

            if (exercise_choice < 1 || exercise_choice > EXERCISES_PER_GROUP ||
                strlen(exercises[group_choice - 1][exercise_choice - 1]) == 0)
            {
                printf("Неверный выбор упражнения.\n");
                return;
            }

            char *selected_exercise = exercises[group_choice - 1][exercise_choice - 1];
            read_trainings_by_exercise(selected_exercise);
            break;
        }
        default:
            printf("Неверный выбор.\n");
            break;
    }
}*/
