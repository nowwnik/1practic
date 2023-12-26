#include <iostream>
using namespace std;

//инициализация дополнитльных функций 
float mini(int n, float* dynamic_array);
float sum(int n, float* dynamic_array);
void sort(int n, float* dynamic_array);

int main()
{
	setlocale(LC_ALL, "Russian"); //подключение русского языка

	int n;//объявление переменной (длина массива)

	cout << "Программа работающая с одномерным динамическим массивом\n"
	//сообщение пользователю
	<< "введите длину массива\n";
	cin >> n;//запрос данных

	float* dynamic_array = new float[n];
	//инициализация массива

	cout << "Вводите элементы массива через Enter\n";
	for (int i = 0; i < n; i++) {
		cin >> dynamic_array[i];  
	}
	//заполнение массива с клавиатуры

	//вызов функций
	cout << "Минимального значение массива: " << mini(n, dynamic_array) << endl;
	cout <<"Сумма элементов между отрицательными значениями: " 
		<< sum(n, dynamic_array) << endl;
	cout << "Отсортированный массив: ";
	sort(n, dynamic_array);
	cout << endl << endl;
}

//функция поиска минимального значения
float mini(int n, float* dynamic_array)
{
	float min = 10000000;//переменная для записи минимума
	for (int i = 0; i < n; i++)
	{
		if (min > dynamic_array[i]) //поиск минимума
			min = dynamic_array[i];
	}
	return min;
}
//функция суммы элементов между отрицательными значениями
float  sum(int n, float dynamic_array[])
{
	float sum = 0; //переменная хранения суммы
	int j = 0;  //индекс ппервого отрицательного элемента
	int i = -1; //индекс посдледнего отрицательного элемента


	for (int k = 0; k < n; k++) 
	{	//поиск элементов
		if (dynamic_array[k] < 0) {
			j = k;
			if (i == -1)
				i = k;
			
		}
	}
	for (int k = i + 1; k < j; k++)
		sum += dynamic_array[k]; //нахождение суммы

	return sum;
}
//сортировка массива по условию
void sort(int n, float* dynamic_array)
{
	int j = 0;//итератор
	float* array = new float[n];//новый массив

	for (int i = 0; i < n; i++)
	{
		if (dynamic_array[i] == 0)
		{
			array[j] = 0; //заполнение массива нулями
			j++;
		}
	}

	for (int i = 0; i < n; i++)
	{	//заполнение массива остальными элементами
		if (dynamic_array[i] != 0)
		{
			array[j] = dynamic_array[i];
			j++;
		}

	}
	
	//печать масива
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}