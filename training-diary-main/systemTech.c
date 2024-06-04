#include "systemTech.h"
#include <windows.h>

void setBackgorundColor() { // Выбор цвета текста консоли
    system("color F0");
}

void setRussianLanguage(){ // Установка кодировки для вывода русского языка
    SetConsoleOutputCP(CP_UTF8);
}

void ClearConsole() { // Очистка консоли
    system("cls");
}