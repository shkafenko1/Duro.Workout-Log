#include "adviceTraining.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROUPS 3
#define MAX_ADVICE_LENGTH 256

typedef struct {
    char group_name[50];
    char advice[MAX_ADVICE_LENGTH];
} Advice;

Advice *generate_advice_list() {
    Advice *advice_list = (Advice *)malloc(GROUPS * sizeof(Advice));
    if (advice_list == NULL) {
        perror("Не удалось выделить память для advice_list");
        exit(EXIT_FAILURE);
    }

    strcpy(advice_list[0].group_name, "Ноги");
    strcpy(advice_list[0].advice, "Совет для тренировки ног: всегда следите за техникой выполнения, чтобы избежать травм.");

    strcpy(advice_list[1].group_name, "Руки");
    strcpy(advice_list[1].advice, "Совет для тренировки рук: не забывайте про разминку перед началом основной тренировки.");

    strcpy(advice_list[2].group_name, "Спина");
    strcpy(advice_list[2].advice, "Совет для тренировки спины: уделяйте внимание правильному положению позвоночника.");

    return advice_list;
}


void generate_advice() {
    Advice *advice_list = generate_advice_list();
    int group_choice;
    printf("Введите для какой группы мышц вы хотите получить совет?:\n1-Ноги\n2-Руки\n3-Спина");
    scanf("%d", &group_choice);
    if (group_choice > 0 && group_choice <= GROUPS) {
        printf("Совет для группы '%s': %s\n", advice_list[group_choice - 1].group_name, advice_list[group_choice - 1].advice);
    } else {
        printf("Неверный выбор группы упражнений.\n");
    }

    free(advice_list);
}