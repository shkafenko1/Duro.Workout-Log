#include "createTraning.h"
#define MAX_EXERCISES 15
#define GROUPS 3
#define EXERCISES_PER_GROUP (MAX_EXERCISES / GROUPS)

// Функции для работы с очередью
void initQueue(Queue *q) { // Инициализация очереди
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) { // Функция проверки на пустой элемент
    return q->front == NULL;
}

void enqueue(Queue *q, Training data) { // Добавление в очередь
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        perror("Не удалось выделить память для нового узла");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;

    if (!q->front) {
        q->front = newNode;
    }
}

Training dequeue(Queue *q) { // Удаление из очереди
    if (isEmpty(q)) {
        perror("Очередь пуста");
        exit(EXIT_FAILURE);
    }
    Node *temp = q->front;
    Training data = temp->data;
    q->front = q->front->next;

    if (!q->front) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void write_training() { // Запись тренировки в файл training.txt
    const char *exercise_names[3][5] = {
            {"Приседания","Жим ногами лежа", "Становая тяга", "Болгарские приседания", "Выпады"},
            {"Отжимания", "Жим штанги лёжа", "Жим гантелей",    "Хаммер", "Кроссовер"},
            {"Подтягивания", "Тяга блока","Гребля","Тяга штанги к поясу", "Пулловер"}
    };
    FILE *file = fopen("training.txt", "a");
    if (!file) {
        perror("Не удалось открыть файл");
        return;
    }

    Queue trainingQueue;
    initQueue(&trainingQueue);

    Training training;
    char duration_input[10];

    printf("Введите дату тренировки (YYYY-MM-DD): ");
    scanf("%10s", training.date);

    printf("Введите продолжительность тренировки (в минутах, или оставьте пустым): ");
    fgets(duration_input, sizeof(duration_input), stdin); // Очистка буфера
    fgets(duration_input, sizeof(duration_input), stdin);
    if (strcmp(duration_input, "\n") == 0) {
        training.duration = 0; // Если введено пустое значение, продолжительность равна 0
    } else {
        training.duration = atoi(duration_input);
    }

    int group_choice, exercise_choice;
    printf("Выберите группу упражнений (1-3):\n1. Ноги\n2. Грудь\n3. Спина\n");
    scanf("%d", &group_choice);

    if (group_choice < 1 || group_choice > GROUPS) {
        printf("Неверный выбор группы упражнений.\n");
        fclose(file);
        return;
    }

    printf("Выберите упражнение (1-%d):\n", EXERCISES_PER_GROUP);
    for (int i = 0; i < EXERCISES_PER_GROUP; i++) {
        printf("%d. %s\n", i + 1, exercise_names[group_choice - 1][i]);
    }
    scanf("%d", &exercise_choice);

    if (exercise_choice < 1 || exercise_choice > EXERCISES_PER_GROUP || strlen(exercise_names[group_choice - 1][exercise_choice - 1]) == 0) {
        printf("Неверный выбор упражнения.\n");
        fclose(file);
        return;
    }

    training.exercise_index[0] = group_choice - 1;
    training.exercise_index[1] = exercise_choice - 1;

    printf("Введите количество повторений: ");
    scanf("%d", &training.repetitions);

    printf("Введите вес, который использовался: ");
    scanf("%f", &training.weight);

    // Добавляем тренировку в очередь
    enqueue(&trainingQueue, training);

    // Записываем все тренировки из очереди в файл
    while (!isEmpty(&trainingQueue)) {
        Training t = dequeue(&trainingQueue);
        fprintf(file, "%s %d %d %d %d %.1f\n", t.date, t.duration, t.exercise_index[0], t.exercise_index[1], t.repetitions, t.weight);
    }

    fclose(file);
    printf("Тренировка успешно записана в файл.\n");
}