#include "questionDataBool.h"
#include <stdio.h>
#include "traningHooks.h"

enum {START ,ADD, CHECK, ADVICE};

void questionData(){

    int questionDataBool; // Переменная, имитирующая логику выбора
    printf("\nВыберите нужный функционал:\n");
    printf("\n1: Добавить тренировку\n2: Просмотреть тренировку\n3: Советы по тренировкам\n");
    scanf("%d", &questionDataBool); // Считывание переменной, имитирующей логику выбора
    switch (questionDataBool) {
        case ADD:
            createTraning(); // Функция добавления тренировок
            break;
        case CHECK:
            reportTraining(); // Функция просмотра тренировки
            break;
        case ADVICE:
            adviceTraning(); // Функция выдачи советов
            break;
        default:
            printf("Неверный ввод"); // Обработка некорректного ввода
            break;
    }
}
