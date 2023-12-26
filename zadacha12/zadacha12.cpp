#include <iostream>
using namespace std;

//инициализация дополнительных функций
double F(double x);
double treugl(double X0, double Xn, double h);
double trap(double X0, double Xn, double h);
double simp(double X0, double Xn, double h);

int main()
{
    setlocale(LC_ALL, "Russian"); //подключение русского языка

    cout << "Программа, вычисляющая определённый интеграл функции\n"
    << "f(x)= (0.1 + x^1/2) / (1 + ln(x)^2) на отрезке [2;4] "
    << "с шaгом h=0.01\n\n"; //пояснение пользователю

    double X0 = 2,Xn = 4, h = 0.01; //исходные данные

    //вызов функций разных методов
    cout << "Методом левых прямоугольников: ";
    cout << treugl(X0, Xn, h) << endl;

    cout << "Методом трапеций: ";
    cout << trap(X0, Xn, h) << endl;

    cout << "Методом Симпсона: ";
    cout << simp(X0, Xn, h) << endl;
}

double F(double x) //функция вычисления значени в точке
{
    return (0.1 + pow(x, 0.5)) / (1 + pow(log(x),2 ));
}

//метод треугольников
double treugl(double X0, double Xn, double h) 
{
    int n = (Xn - X0) / h - 1; //число интераций
    double S = 0;//значение интеграла (сумма)
    double x = X0; //"шагающий" х
    for (int i = 0; i < n; i++)
    {
        S += F(x);  //счёт суммы
        x = X0 + i * h; //шаг х
    }
    return h * S;//возврат значения интеграла
}

//метод трапеций 
double trap(double X0, double Xn, double h)
{
    int n = (Xn - X0) / h; //число итераций
    double S = 0; //значение интеграла (сумма)
    double x = X0; //"шагающий" х
    for (int i = 1; i < n; i++)
    {
        S += F(x);  //счёт суммы
        x = X0 + i * h; //шаг х
    }

    return h * ((F(X0) + F(Xn)) / 2 + S); //возврат значения интеграла

}

//метод Симпсона
double simp(double X0, double Xn, double h)
{
    int n = (Xn - X0) / (2*h) - 1; //число итераций
    double S = 0; //значение интеграла (сумма)
    double x = X0; //"шагающий" х
    for (int i = 1; i < n+1; i+=2)
    {
        S += F(x); //счёт суммы нечтных шагов
        x = X0 + i * h; //шаг х
    }
    S *= 4; //счёт четырёхкратной суммы нечётных шагоы
    x = X0; //обновление х
    for (int i = 0; i < n+1; i+=2)
    {
        S += F(x); //счёт суммы чётного значения
        x = X0 + i * h; //шаг х
    } 
    x = X0; //обновление х
    for (int i = 2; i < n+1; i+=2)
    {
        S += F(x); //счёт суммы каждого чётного значения
        x = X0 + i * h; //шаг х
    }
    return S * h/3; //возврат значения интеграла
}