#include <iostream>

using namespace std;

///Вариант 11 - Задание 2
///Создать структуру ДатаВремя (Секунда, Минута, Час,  День, Месяц, Год).
///Выполнить преобразования даты в формате cc:мм:чч ДД-ММ-ГГГГ) в тип структуры ДатаВремя.

typedef struct DateTime{
    int seconds;
    int minutes;
    int hours;
    int days;
    int month;
    int years;
    bool isValid;
} DateTime;

DateTime convertData(string line){
    DateTime dateTime;

    int seconds = -1;
    int minutes = -1;
    int hours = -1;
    int days = -1;
    int month = -1;
    int years = -1;

    cout<<"Дата: "<<line<<endl;

    sscanf(line.c_str(), "%i:%i:%i %i-%i-%i", &seconds, &minutes,&hours, &days, &month, &years);

    if (seconds<=60 && minutes<=60 && hours<=60 && days<=31 && days!=0 && month<=12 && month!=0) {
        dateTime = {seconds, minutes, hours, days, month, years};
        dateTime.isValid = true;
        return dateTime;
    }
    
    dateTime.isValid = false;
    cout<<"Введенная дата имеет неверный формат!"<<endl;
    return dateTime;
}

int main() {
    string enteredDate;
    cout<<"Введите дату в формате сс:мм:чч ДД-ММ-ГГГГ"<<endl;
    getline(cin, enteredDate) ;
    DateTime  dateTime = convertData(enteredDate);

    if (dateTime.isValid){
        cout<<"Считанная дата"<<endl;
        cout<<"Секунды: "<<dateTime.seconds<<endl;
        cout<<"Минуты: "<<dateTime.minutes<<endl;
        cout<<"Часы: "<<dateTime.hours<<endl;
        cout<<"Дни: "<<dateTime.days<<endl;
        cout<<"Месяцы: "<<dateTime.month<<endl;
        cout<<"Года: "<<dateTime.years<<endl;
    }

    return 0;
}
