#include <iostream>
using namespace std;

//инициализация дополнительных функций
double dihotom1(double a, double b, double Eps);
double dihotom2(double a, double b, double Eps);
double f(double x);

int main()
{
	setlocale(LC_ALL, "Russian"); //полключение русского языка

	cout << "Программа нахождения корня уравнения 0.25x^3+4x^2-0.22\n"
	<< "методом дихотомии на отрезке [-10;10] c точностью 10^-6\n"; //пояснение пользователю

	double a = -10, b = 10, Eps = 0.000001; //объявление переменных
	
	cout << "Корни уравнения: "
		<< dihotom1(a, b, Eps) << "; " << dihotom2(a, b, Eps) << endl << endl;
	//вызов функций
}

//метод дихотомии
double dihotom1(double a, double b, double Eps)
{
	double c = 0.5 * (a + b); //середина отрезка
	while ((b-a) > Eps)
	{
		if (b - a < 2 * Eps) //возможный корень по условию задачи
		{					 //(быстрое решение)
			return c;
			exit(0);
		}
		if (f(c) == 0)	//(быстрое решение)
		{
			return c;
			exit(0);
		}
		if (f(a) * f(c) < 0) //сужение отрезка
			b = c;
		else
			a = c;
		c = 0.5 * (a + b);
	}
	return c;
}
//метод дихотомии на случай второго корня(почти симметричного)
double dihotom2(double a, double b, double Eps)
{
	double c = 0.5 * (a + b);
	while ((b - a) > Eps)
	{
		if (b - a < 2 * Eps) //возможный корень по условию задачи
		{					 //(быстрое решение)
			return c;
			exit(0);
		}
		if (f(c) == 0) //(быстрое решение)
		{
			return c;
			exit(0);
		}
		if (f(c) * f(b) < 0) //сужение отрезка 
			a = c;
		else
			b = c;

		c = 0.5 * (a + b);
	}
	return c;
}
//вычисление значения
double f(double x)
{
	return (0.25 * x * x * x) + (4 * x * x) - 0.22;
}