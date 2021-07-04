#include <string>
#include <iostream>
#include <fstream>

using namespace std;

///Вариант 11 - Задание 1
///Написать программу, которая считает знаки препинания в каждой строке.

void countDividers() {

    int signsCount = 0;
    int linesCount = 1;

    ifstream fs ("file.txt");

    string  line;
    if (fs.is_open())
    {
        while ( getline (fs,line) )
        {
            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == ',' || line[i] == '.' || line[i] == ':' || line[i] == ';' || line[i] == '!' || line[i] == '?'){
                    signsCount++;
                }
            }
            if(signsCount!=0){
                cout<<"Строка "<<linesCount<<" содержит"<<signsCount<<" знак(ов) препинания"<<endl;
            } else {
                cout<< "В строке "<<linesCount<< " не обнаружено знаков препинания"<<endl;
            }
            linesCount++;
            signsCount = 0;
        }
        fs.close();
    }
    else cout << "Не удалось открыть файл\n";
}

int main() {
    countDividers();
    return 0;
}


