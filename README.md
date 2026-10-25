# Задание номер 3 к лабораторной работе 6
## 1. Условие задачи
Дано число N (N<1000). Написать программу, которая проверяет является кратна ли его сумма цифр трем.

## Блок-схема
https://sun9-47.vkuserphoto.ru/s/v1/ig2/n66NJUNwDqOpQnsFPWVpiDPNdfgOiv3ei515jcrDjHjgPRTx-UMw_RksnIPL7WpV4GbqQgbGvNrhw4Ifj6hIZ8Mi.jpg?quality=95&as=32x19,48x28,72x42,108x64,160x94,240x142,360x212,480x283,540x319,640x377,720x425,1080x637,1280x755&from=bu&u=tNZsdjDR4yXvUEDbl4ToFGPkQkVqSFRtI9NkpexMEtk&cs=1280x0

## 2. Реализация программы
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // модуль числа

int sum3(int n);

int sum3(int n) 
{
    int numb = abs(n); // если пользователь ввёл отрицательное число - берём модуль


    int hundreds = numb / 100; // для сотен
    int tens = (numb / 10) % 10; // сначала отбрасываем делением единицы, затем берём остаток от деления на 10
    int units = numb % 10; // сразу берём остаток от деления на 10

    int sum = hundreds + tens + units;

    return (sum % 3 == 0) ? 1 : 0;
}

int zad3(void) // вариант 18
{
    int n, result;

    printf("введите целое число (N < 1000): ");
    scanf("%d", &n);

    if (abs(n) >= 1000) {
        printf("число должно быть меньше 1000.\n");
        return 0;
    }

    result = sum3(n);
    printf("cумма цифр числа %d %s кратной 3.\n", n, (result == 1) ? "является" : "не является");
    return 1;
}


int main()
{
    setlocale(LC_ALL, "RUS");
    zad3();
    return 0;
}


## 3. Результаты работы программы
введите целое число (N < 1000): 321
cумма цифр числа 321 является кратной 3.

## 4. Информация о разработчике
Матюхина Софья, бИД-261
