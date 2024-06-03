#include "systemTech.h"
#include <windows.h>

void setBackgorundColor() { // Выбор цвета текста консоли
    /*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7, B);*/
    system("color F0");
}

void setRussianLanguage(){ // Установка кодировки для вывода русского языка
    SetConsoleOutputCP(CP_UTF8);
}

void ClearConsole() { // Очистка консоли
    system("cls");
}