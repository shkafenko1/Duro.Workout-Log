#ifndef TRAINING_DIARY_CREATETRANING_H
#define TRAINING_DIARY_CREATETRANING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
void write_training();

typedef struct Node { // Узел очереди
    Training data; // Данные из узла
    struct Node *next; // Указатель на следующий элемент
} Node;

typedef struct { // Структура очереди
    Node *front; // Передний элемент очереди
    Node *rear; // Задний элемент очереди
} Queue;

#endif