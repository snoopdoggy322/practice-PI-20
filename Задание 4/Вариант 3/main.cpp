#include <iostream>
#include <string.h>

using namespace std;

int CatValue(int ValFirst, int ValSecond)
{
    ValFirst = ValFirst * 10 + ValSecond;
    return ValFirst;
}


void MulFive(string str, unsigned int* mas_div, unsigned int* mas_answer)
{
    int length = str.length();          //Длина строки
    int remainder = 0, value = 0;       //Остаток и значение для целочисленного деления
    for (int i = 0; i < length; i++)    //Инициализация массива, путём ввода строки цифр в массив типа int
    {
        mas_div[i] = (int)str[i] - 48;
    }
    {
    }
    int j = 0;
    value = mas_div[0] / 2;         //Целое первой цифры
    mas_answer[j] = value;
    remainder = mas_div[0] % 2;     //Находим возможный остаток первой цифры
    j++;
    for (int i = 1; i < length; i++)
    {
        value = CatValue(remainder, mas_div[i]) / 2;
        mas_answer[j] = value;
        remainder = mas_div[i] % 2;
        j++;
    }
    cout << "\tОтвет: ";
    for (int j = 0; j < length; j++)    //Вывод массива с ответом
    {
        cout << mas_answer[j];
    }
}


//Управление работой программы
int main()
{
    unsigned int* mas_div, * mas_answer;
    string str;
    cout << "\n\tВведите число: ";
    cin >> str;
    mas_div = (unsigned int*)calloc(str.length(), sizeof(unsigned int));       //Выделение памяти calloc
    mas_answer = (unsigned int*)calloc(str.length(), sizeof(unsigned int));
    MulFive(str, mas_div, mas_answer);
    int remainder = (int)str.back() - 48;
    cout << remainder % 2 ? '0' : '5';
    return 0;
}