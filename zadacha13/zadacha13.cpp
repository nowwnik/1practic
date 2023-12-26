#include <iostream>
#include <string.h>
using namespace std;

//инициализация дополнительных функций
double digit_out(string str);
void digit_percent(string str);

int main()
{
	setlocale(LC_ALL, "Russian"); //подключение русского языка

	cout << "Программа работающая со строкой\n";
	cout << "Введите строку текста из прописных и строчных "
	<< "латинских букв и цифр\n";//пояснение пользователю

	string str;//объявление строки
	cin >> str;//чтение строки

	digit_percent(str);//вызов функции
	cout << endl << endl;
}
//функция выводит все цифры в строку
double digit_out(string str)
{	
	double counter=0;//счётчик кол-ва цифр
	cout << "Только цифры, входящие в этот текст: ";
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 48 and str[i] <= 57)//индексы цифр в ASCII
		{
			cout << str[i];
			counter++;
		}
	}
	return counter;
}
//функция вызывает предыдущию и находит процентное соотношение
void digit_percent(string str)
{
	cout << endl << "Процентное содержание цифр в исходном тексте: "
	<< (digit_out(str) / str.size()) * 100 << "%";
}