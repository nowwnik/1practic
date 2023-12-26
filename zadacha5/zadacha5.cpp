#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define SIZE 3
//размер матрицы

//объявлеине дополнительных функций
void generateMatrix(int m[][SIZE]);
void inputMatrix(int m[][SIZE]);
void randomMatrix(int m[][SIZE]);
void printMatrix(int m[][SIZE]);
void proizv(int m[][SIZE]);
void debug(int type);

int main()
{
    setlocale(LC_ALL, "Russian");

    int mass[SIZE][SIZE], type; //объявление массива и условия

    cout << "Программа работающая с квадратной матрицей\n";
    //сообщение пользователю
    cout << "Каким образом вы хотите задать матрицу?\n"
    << "1 - набор с клавиатуры\n2 - случайный массив\n"
    << "3 - значения по умолчанию\n";

    cin >> type;//запрос способа
    cout << endl;

    if (type == 2)
        generateMatrix(mass);
    if (type == 1)
        inputMatrix(mass);
    if (type == 3)
        randomMatrix(mass);
    //инициализация матрицы

    debug(type);//проверка корректности ввода

    printMatrix(mass);//вывод матрицы

    cout << endl;

    proizv(mass);//выполнение задачи

    return 0;
}

//функция случайного заполнения матрицы
void generateMatrix(int m[][SIZE])
{
    srand(time(0));//раном
    int i, j;
    //заполнение матрицы
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            m[i][j] = -10 + rand() % 50;
}

//функция вывода матрицы
void printMatrix(int m[][SIZE])
{
    int i, j;
    //печать матрицы
    for (i = 0; i < SIZE; i++)
    {
        printf("%d:    ", i + 1);
        for (j = 0; j < SIZE; j++)
            printf("%3d ", m[i][j]);
        puts("");
    }
}

//функция заполнения значениями по умолчанию 
void randomMatrix(int m[][SIZE])
{
    int i, j;
    //заполнение матрицы
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            m[i][j] = rand() % 10;
}

//функция заадния матрицы с клавиатуры
void inputMatrix(int m[][SIZE])
{
    //считывание элементов матрицы
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "mass[" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }
        cout << endl;
    }
}

//функция вычисления спроизведения нужных строк
void proizv(int m[][SIZE])
{
    int i, j;
    int flag = 0;//флаг проверки условия наличия отрицательного элемента
    int p = 1;//произведение
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {   //проверка строки
            if (m[i][j] < 0) flag = 1; p *= m[i][j];
        }
        if (!flag)
        {   //печать строки
            printf("Строка %d не содержит отрицательных чисел. Произведение: %d\n", i + 1, p);
        }
        flag = 0;//обнуление флага
        p = 1;//обнуление произведения
    }
}

//функция проверки корректности ввода
void debug(int type)
{   //проверка выбора метода
    if (type > 3 or type < 1)
    {
        cout << "НЕКОРРЕКТНЫЙ ВВОД";
        exit(0);
    }
}