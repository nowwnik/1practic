#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian"); //подключение русского языка

    int n, buf=0; //объявление переменных 
    //n - кол-во чисел; buf - буферная переменная для упрощения задачи
 
    cout << "Программа заполнения текстовых файлов целыми числами\n"; //пояснение пользователю
    
    cout << "Введите количество чисел, которое нужно сгенерировать ";

    cin >> n; //запрос количества чисел

    srand(time(NULL));//для рандома

    ofstream output1; // первый поток

    output1.open("D:\\OUTPUT1.dat"); // открытие первого файла

    ofstream output2; // второй поток

    output2.open("D:\\OUTPUT2.dat"); // открытие первого файла


    for (int i = 0; i < n; i++)
        {
            buf = rand();
            output1 << buf << " "; //запись в первый файл

            if (buf % 2 == 0)
                output2 << buf << " "; //запись во второй файл
        }

   
    output1.close();//закрытие первого файла
    output2.close();//закрытие второго файла
   
    cout << "Программа завершила работу" << endl
        << "Файл заполненный числами находится D:\\OUTPUT1.dat"<<endl
        << "Файл содержащий только чётные числа первого D:\\OUTPUT2.dat"<<endl<<endl;
}

