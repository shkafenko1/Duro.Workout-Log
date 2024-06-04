#include "adviceTraining.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROUPS 3
#define MAX_ADVICE_LENGTH 500

typedef struct {
    char group_name[15];
    char advice[MAX_ADVICE_LENGTH];
} Advice;

Advice *generate_advice_list() {
    Advice *advice_list = (Advice *)malloc(GROUPS * sizeof(Advice));
    if (advice_list == NULL) {
        perror("Не удалось выделить память для advice_list");
        exit(EXIT_FAILURE);
    }

    strcpy(advice_list[0].group_name, "Ноги");
    strcpy(advice_list[0].advice, "Для эффективной тренировки нижней части тела рекомендуется уделять регулярное внимание ключевым мышечным группам, таким как квадрицепсы, ягодичные мышцы и мышцы задней поверхности бедра.");

    strcpy(advice_list[1].group_name, "Грудь");
    strcpy(advice_list[1].advice, "Для эффективной тренировки верхней части тела рекомендуется уделять регулярное внимание ключевым мышечным группам, таким как большая грудная мышца, малая грудная мышца и передняя зубчатая мышца.");

    strcpy(advice_list[2].group_name, "Спина");
    strcpy(advice_list[2].advice, "Для эффективной тренировки мышц спины рекомендуется уделять регулярное внимание ключевым мышечным группам, таким как широчайшие мышцы спины, трапециевидные мышцы и ромбовидные мышцы.");

    return advice_list;
}


void generate_advice() {
    Advice *advice_list = generate_advice_list();
    int group_choice;
    printf("Введите для какой группы мышц вы хотите получить совет?:\n1-Ноги\n2-Грудь\n3-Спина\n");
    scanf("%d", &group_choice);
    if (group_choice > 0 && group_choice <= GROUPS) {
        printf("Совет для группы '%s': \n%s\n", advice_list[group_choice - 1].group_name, advice_list[group_choice - 1].advice);
    } else {
        printf("Неверный выбор группы упражнений.\n");
    }

    free(advice_list);
}