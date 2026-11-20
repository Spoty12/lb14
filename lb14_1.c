
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

#define N 100

// Функция из задания 8
double F(double x)
{
    return x * x * x + 3 * x * x - 3;
}

// Задание 1. Заполнение массива
double* full_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        double x = 2.0 + (double)rand() / RAND_MAX * 2.0;
        ptr_array[i] = F(x);
    }

    return ptr_array;
}

// Задание 1. Вывод массива
int put_elements(double* ptr_array, int n)
{
    printf("\nИсходный массив:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%8.2f ", ptr_array[i]);

        if ((i + 1) % 5 == 0)
            printf("\n");
    }

    printf("\n");
    return n;
}

// Задание 1. Обработка массива
double* calc_elements(double* ptr_array, int n)
{
    double sum_positive = 0;
    double sum_negative = 0;

    int count_positive = 0;
    int count_negative = 0;

    for (int i = 0; i < n; i++)
    {
        if (ptr_array[i] > 0)
        {
            sum_positive += ptr_array[i];
            count_positive++;
        }
        else if (ptr_array[i] < 0)
        {
            sum_negative += ptr_array[i];
            count_negative++;
        }
    }

    printf("\nРезультаты обработки массива:\n");
    printf("Сумма положительных элементов: %.2f\n", sum_positive);
    printf("Сумма отрицательных элементов: %.2f\n", sum_negative);
    printf("Количество положительных элементов: %d\n", count_positive);
    printf("Количество отрицательных элементов: %d\n", count_negative);

    if (count_positive > 0)
    {
        printf("Среднее значение положительных элементов: %.2f\n",
            sum_positive / count_positive);
    }
    else
    {
        printf("Положительных элементов нет.\n");
    }

    return ptr_array;
}

// Задание 2. Сумма элементов от begin до end включительно
double sum_elements(double* ptr_array, int begin, int end)
{
    double sum = 0;

    for (int i = begin; i <= end; i++)
    {
        sum += ptr_array[i];
    }

    return sum;
}

// Задание 2. Поиск заданного элемента
int find_element(double* ptr_array, int n, double element)
{
    for (int i = 0; i < n; i++)
    {
        if (fabs(ptr_array[i] - element) < 0.000001)
        {
            return i;
        }
    }

    return -1;
}

// Задание 3. Вариант 9.
// Поиск максимального по модулю элемента,
// не равного заданному A
double max_abs_not_equal(double* ptr_array, int n, double A)
{
    double max_element = 0;
    double max_abs = -1;
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (fabs(ptr_array[i] - A) >= 0.000001)
        {
            if (fabs(ptr_array[i]) > max_abs)
            {
                max_abs = fabs(ptr_array[i]);
                max_element = ptr_array[i];
                found = 1;
            }
        }
    }

    if (found)
        return max_element;

    return NAN;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    double array[N];
    int size;

    srand((unsigned int)time(NULL));

    printf("Введите размер массива (от 1 до %d): ", N);

    if (scanf("%d", &size) != 1 || size < 1 || size > N)
    {
        printf("Ошибка! Неверный размер массива.\n");
        return 1;
    }

    // Задание 1
    full_elements(array, size);
    put_elements(array, size);
    calc_elements(array, size);

    // Задание 2. Сумма элементов диапазона
    int begin, end;

    printf("\nВведите начальный индекс begin: ");
    if (scanf("%d", &begin) != 1)
        return 1;

    printf("Введите конечный индекс end: ");
    if (scanf("%d", &end) != 1)
        return 1;

    if (begin >= 0 && begin <= end && end < size)
    {
        double sum = sum_elements(array, begin, end);

        printf("Сумма элементов от %d до %d: %.2f\n",
            begin, end, sum);
    }
    else
    {
        printf("Ошибка! Неверно указаны индексы.\n");
    }

    // Задание 2. Поиск элемента
    double a;

    printf("\nВведите искомый элемент a: ");
    if (scanf("%lf", &a) != 1)
        return 1;

    int index = find_element(array, size, a);

    if (index != -1)
    {
        printf("Элемент найден! Индекс: %d\n", index);
    }
    else
    {
        printf("Элемент не найден.\n");
    }

    // Задание 3. Вариант 9
    double A;

    printf("\nВведите значение A для задания 3: ");
    if (scanf("%lf", &A) != 1)
        return 1;

    double result = max_abs_not_equal(array, size, A);

    if (!isnan(result))
    {
        printf("Максимальный по модулю элемент, не равный A: %.2f\n",
            result);
        printf("Модуль найденного элемента: %.2f\n", fabs(result));
    }
    else
    {
        printf("Нет элементов, отличных от A.\n");
    }

    return 0;
}
