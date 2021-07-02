#include <iostream>
#include <fstream>
#include <string>
#include <string.h >
#pragma warning(disable : 4996)

using namespace std;

int main(void)
{
    string s;

    string* AS; // массив вводимых строк, это результат
    string* AS2; // дополнительный массив строк
    int count; // количество элементов в массиве
    //string s; // дополнительная переменная-строка
    char buf[80]; // буфер для ввода строк
    // цикл ввода строк, конец ввода - пустая строка ""
    cout << "Enter strings:\n";
    count = 0;
    int  result = 0;
    AS = nullptr;

    do
    {
        // ввести строку в массив типа char[]
        cout << "=> ";
        cin.getline(buf, 80, '\n'); // строки вводятся с пробелами

        // скопировать строку char[] в строку типа string
        s = buf;

        // если введена не пустая строка
        if (s != "")
        {
            // увеличить количество строк
            count++;
            if (s[0] != s[s.length() - 1]) result = result + 1;

            // освободить память для нового массива
            AS2 = new string[count];

            // скопировать данные из старого массива в новый
            for (int i = 0; i < count - 1; i++)
                AS2[i] = AS[i];

            // добавить введенную строку в новый массив
            AS2[count - 1] = s;

            // освободить память, выделенную под старый (предыдущий) массив
            if (AS != nullptr)
                delete[] AS;

            // перенаправить указатель из предыдущего массива AS на массив AS2
            AS = AS2;
        }
    } while (s != "");

    // вывести созданный массив AS на экран
    cout << "\nArray AS is as follows:\n";
    if (count > 0)
        for (int i = 0; i < count; i++)
            cout << "AS[" << i << "] = " << AS[i] << ::endl;
    else
        cout << "array AS is empty.";

    delete[] AS;
    cout << "In the text " << result << " string(s) that not begin and end with the same character" << endl;
    system("pause");
    return 0;
}
