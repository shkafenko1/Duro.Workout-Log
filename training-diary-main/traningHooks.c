#include "traningHooks.h"
#include "createTraning.h"
#include "checkTraining.h"
#include "systemTech.h"
#include "adviceTraining.h"

void createTraning(){ // Функция для создания тренировки
    ClearConsole();
    write_training();
}

void reportTraining(){ // Функция для вывода тренировок
    ClearConsole();
    checkTraining();
}

void adviceTraning(){ // Функция для вывода советов
    ClearConsole();
    generate_advice();
}