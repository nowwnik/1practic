#include <iostream>
using namespace std;

//инициализация дополнительных функций
double function(double X0, double Y0);
void euler(double h, double X0, double Y0, int n);
double reshenie(double Xn);

int main()
{
	setlocale(LC_ALL, "Russian"); //подключение русского языка

	double X0=1, Xn=2,Y0=3, h; //исходные данные
	int n; //объявление переменных
	
	cout << "Программа нахождения решения дифференциального уравнения\n"
	<< "y`=(y^2-2x^2)/2xy  методом Эйлера\n"; //пояснение пользователю

	cout << "Введите начало отрезка X0: ";
	cin >> X0;
	cout << "Введите конец отрезка Xn: ";
	cin >> Xn;
	cout << "Введите значение Y0 в X0: ";
	cin >>  Y0;
	cout << "Ведите шаг: ";
	cin >> h;
	//ввод данных

	n = int((Xn - X0) / h); //кол-во узлов сетки

	euler(h, X0, Y0, n);	//вызов функции метода
		
	cout << endl << "Точное значение: " << reshenie(Xn);
	//вызов точного значения
}

//данная функция
double function(double X0, double Y0)
{
	return (Y0 * Y0 - 2 * X0 * X0) / (2 * X0 * Y0);
}
//счёт численного метода
void euler(double h, double X0, double Y0, int n)
{
	cout << endl << "Вычисленные численные значения\n";
	cout << "X[0] = " << X0 << "    Y[0] = " << Y0 << endl;
	//начало сетки

	for (int i = 1; i <= n; i++)
	{
		Y0 += h * function(X0, Y0); //вычисление у
		X0 += h; //шаг с х
		//печать значений
		cout << "X[" << i << "] = " << X0 << "  Y[" << i << "] = " << Y0 << endl;
	}
}
//вычисление точного значения
double reshenie(double Xn)
{
	double Z=0; //инициализация переменной
	Z = 11 * Xn - 2 * Xn * Xn; //вычисление подкоренного
	Z = pow(Z, 0.5); //вычисление корня
	return Z;
}