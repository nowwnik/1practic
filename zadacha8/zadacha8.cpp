#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //подключение русского языка

    ifstream fin;
    fin.open("D:\\INPUT.dat"); //открытие входного файла
    
    ofstream fout;
    fout.open("D:\\OUTPUT.dat"); // открытие выходного файла

    //объявление переменных
    int size = -1, maxI = 0, minI = 0;
    //size - интерационная переменная (-1 для компенсации при считываинии файла
    //maxI, minI - индексы максимального и минимального элемента
    double max = -100000, min = 100000;
    //хранение значений макимума и минимума
    string min_buf, max_buf;
    //строковые буферные переменный для перезаписи в новый файл

    cout << "Программа меняющая местами мексимальный и минимальный "
        << "элементы файла\n" << "Входной файл D:\\INPUT.dat";
               //пояснение пользователю
  
    while (!fin.eof())//прочетение файла
    {
        string str;
        fin >> str;
        size++;//счётчик чисел в файле

        if (!fin.eof())
        {
            if (stod(str) < min) //нахождение минимума
            {
                min = stod(str);
                min_buf = str; //запись элемента в строчном формате
                minI = size; //запоминание индекса элемента
            }

            if (stod(str) > max) //нахождение максимума
            {
                max = stod(str);
                max_buf = str; //запись элемента в строчном формате
                maxI = size; //запоминание индекса элемента
            }

        }
     
    } 


    fin.close();
    fin.open("D:\\INPUT.dat"); //переоткрытие файла для повторного прочтения

    string* buf = new string[size]; //массив для перезаписи
    size = 0; //обнуление итератора перед масивом 

    while (!fin.eof())//повторное прочтение файла
    {
        string str;
        fin >> str;
        if (!fin.eof())
        {
            buf[size] = str; //запись данных в массив
            size++;
        }
    }

    buf[maxI] = min_buf; //перестановка минимума
    buf[minI] = max_buf; //перестановка максимума

    for (int i = 0; i < size; i++)
        fout << buf[i] << " "; //записть в выходной файл

    fin.close();//закрытие входного файла
    fout.close();//закрытие выходного файла

    cout << endl << "Максимальный элемент файла: " << max << endl
        << "Минимальный элемент файла: " << min << endl
        << "Изменённый файл D:\\OUTPUT.dat";//для пользователя
}
