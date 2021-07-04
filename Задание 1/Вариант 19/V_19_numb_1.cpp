
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

void func()
{

    char str[100];
    int counter = 0;
    cout << "Введите строку: " << endl;
    gets_s(str);
    int N = strlen(str);
    if (N != 0) {
        cout << "Вот ваша строка: " << str << endl;


        for (int i = 0; i < N; i++)
        {
            bool uniqueSymbol = true; // признак того, что символ ранее не встречался
            if (i > 0)
                for (int k = (i - 1); k >= 0; k--)
                    if (str[k] == str[i])
                        uniqueSymbol = false;

            if (uniqueSymbol)
            {
                cout << str[i] << " - ";
                for (int j = 0; j < N; j++)
                    if (str[i] == str[j])

                        counter++;
                cout << counter << endl;
                counter = 0;
            }

        }
    }
    else {
        cout << "Пустая строка " << str << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    func();

    return 0;

}