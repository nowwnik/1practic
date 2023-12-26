#include <iostream>
#include <string.h>
using namespace std;

//инициализация дополнительной функции
void re_str(string str);

int main()
{
	setlocale(LC_ALL, "Russian");
	
	cout << "Программа, работающая с массивом заданным строкой\n";//пояснение пользователю 

	cout << "Введите строку целых чисел через запятую (,)\n";
	
	string str;//инициализация строки
	cin >> str;//чтение строки
	
	cout << "Новая строка, содержащая только чётные числа исходной: ";
	re_str(str);//вызов функции
	cout << endl << endl;
}

//функция перезаписи строки
void re_str(string str)
{
	int* re_str = new int[str.size()]();//новый пустой массив
	int flag=0; //флаг наличия символа "-"
	int j = 0; //итератор

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-')
			flag = 1;//если число отрицательное

		if (str[i] >= 48 and str[i] <= 57)
			re_str[j] = re_str[j] * 10 + (int(str[i]) - 48);
			//перевод строки в число
		
		if (str[i] == ',')
		{
			if (flag == 1)
				re_str[j] = -re_str[j];
				//перевод числа в отрицательное			
			j++;
			flag = 0;//опускание флага
		}

	}	
	
	//печать нужных элементов
	for (int i = 0; i <= j; i++)
	{
		if (re_str[i] % 2 == 0)
		{
			cout << re_str[i] << ",";
		}
	}
}
