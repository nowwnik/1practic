#include <iostream>
using namespace std;

//объявление дополнительных функций
double rezist(double type, double r1, double r2);
bool debug(double type, double r1, double r2);

int main()
{
    double type, r1, r2;
    //объявление переменных 
    //type - тип цепи
    //r1, r2 - сопротивления элементов

    setlocale(LC_ALL, "Russian");
    //подключение русского языка

    cout << "Программа вычисляющая сопротивления электрической цепи,"
    << "состоящей из двух элементов.\n\n";
    //пояснения пользователю 

    cout << "Введите 1 для параллельного соединения, 2 – для последовательного\n";
    cin >> type;
    //выбор типа цепи

    cout << "Введите сопротивления элементов в Омах\n";
    cin >> r1 >> r2;
    //запрос данных


    if (debug(type, r1, r2))//проверка корректности данных 
    cout << "Эквивалентное сопротивление цепи " << rezist(type, r1, r2) << " Ом\n\n\n";
    //вычисление сопротивления

    else cout << "Данные введены некорректно";
}

//функция вычисления сопротивления
double rezist(double type, double r1, double r2)
{
    if (type == 1)  return (r1 * r2) / (r1 + r2); //параллельное соединение

    else if (type == 2) return r1 + r2; //последовательное соединение

    else return 0; //невозможно вычислить
}

//функция, проверяющая корректность данных
bool debug(double type, double r1, double r2)
{
    if (r1 < 0 or r2 < 0 or r1 + r2 == 0) return false; //проерка неотрицателньости

    else if (rezist(type, r1, r2) == 0) return false; //нулевое значение

    else return true; //данные корректны
}
