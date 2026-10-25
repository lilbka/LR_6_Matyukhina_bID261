#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // модуль числа

int check_year(int year);
double F(double x);
int sum3(int n);

int main()
{
    setlocale(LC_ALL, "RUS");

    // задание 1

    int year, result_year;
    printf("введите год: ");
    scanf("%d", &year);

    result_year = check_year(year);

    if (result_year == 1) 
    {
        printf("год %d является високосным\n\n\n", year);
    }
    else 
    {
        printf("год %d не високосный\n\n\n", year);
    }

    // задание 2 (вариант 2???) 

    double x, result_F;
    printf("введите значение x: ");

    scanf("%lf", &x);

    result_F = F(x);

    printf("F(%.2lf) = %.4lf\n", x, result_F);
    printf("была использована ветвь: %s\n\n\n", (x >= 3) ? "x >= 3" : "x < 3"); //тернальный оператор, если использована первая ветвь - выводится первое значение, иначе - второе

    // задание 3 (вариант 18) 

    int n, result_sum3;
    printf("введите целое число (N < 1000): ");
    scanf("%d", &n);

    if (abs(n) >= 1000) 
    {
        printf("число должно быть меньше 1000.\n");
    }
    else 
    {
        result_sum3 = sum3(n);
        printf("cумма цифр числа %d %s кратной 3.\n", n, (result_sum3 == 1) ? "является" : "не является");
    }

    return 0;
}

int check_year(int year)
{
    int cratnost = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0; //тернальный оператор, что-то типа bool. верное левое - возвращает 1, иначе - 0
    return cratnost;
}

double F(double x)
{
    double f;
    if (x >= 3)
    {
        f = -pow(x, 2) + 3 * x + 9;
    }
    else 
    {
        f = x / (pow(x, 3) - 6);
    }
    return f;
}

int sum3(int n)
{
    int numb = abs(n); // если пользователь ввёл отрицательное число - берём модуль

    int hundreds = numb / 100; // для сотен
    int tens = (numb / 10) % 10; // сначала отбрасываем делением единицы, затем берём остаток от деления на 10
    int units = numb % 10; // сразу берём остаток от деления на 10

    int sum = hundreds + tens + units;

    return (sum % 3 == 0) ? 1 : 0;
}
