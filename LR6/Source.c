#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // модуль числа

double F(double x);

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

double F(double x) 
{
    double f;

    if (x >= 3) {
        f = -pow(x, 2) + 3 * x + 9;
    }
    else {
        f = x / (pow(x, 3) - 6);
    }

    return f;
}

int check_year(int year)
{
    int cratnost = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0; //тернальный оператор, что-то типа bool. верное левое - возвращает 1, иначе - 0

    return cratnost;
}

int zad1(void)
{
    int year;

    printf("введите год: ");
    scanf("%d", &year);

    int result = check_year(year);

    if (result == 1) {
        printf("год %d является високосным\n", year);
    }
    else {
        printf("год %d не високосный\n\n\n", year);
    }

    return 0;
}

int zad2(void) // вариант 2???
{
    double x, result;

    printf("введите значение x: ");
    scanf("%lf", &x);

    result = F(x);

    printf("F(%.2lf) = %.4lf\n", x, result);
    printf("была использована ветвь: %s\n\n\n", (x >= 3) ? "x >= 3" : "x < 3"); //тернальный оператор, если использована первая ветвь - выводится первое значение, иначе - второе

    return 0;
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

    zad1();
    zad2();
    zad3();

    return 0;
}
