//Вариант 10
//Дана структура Дата, состоит из трех полей целого типа(День, Месяц и Год).
//Необходимо написать функцию, определяющую предыдущий к дате день.


#include<iostream>
#include<cstdlib>
#include <clocale>
#include <cstdlib>

using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

Date PreviousDay(Date day1);
bool isValidDate(Date day1);

int main()
{
	Date day1, day2;
	setlocale(LC_ALL, "Ru");
	cout << "Введите день (в формате XX):" << endl;
	cin >> day1.day;
	cout << "Введите месяц (в формате XX):" << endl;
	cin >> day1.month;
	cout << "Введите год (в формате XXXX):" << endl;
	cin >> day1.year;
	if (isValidDate(day1) == true) 
	{
		day2 = PreviousDay(day1);
		cout << "Предыдущий к введенной дате день: " << day2.day << endl;
	}
	else 
	{
		cout << "Неверно введена дата!" << endl;
		return 0;
	}

	return 0;
}


bool isValidDate(Date day1)
{
	if (!(1 <= day1.month && day1.month <= 12) || (!cin))
		return false;
	if (!(1 <= day1.day && day1.day <= 31) || (!cin))
		return false;
	if ((day1.day == 31) && (day1.month == 2 || day1.month == 4 || day1.month == 6 || day1.month == 9 || day1.month == 11) || (!cin))
		return false;
	if ((day1.day == 30) && (day1.month == 2) || (!cin))
		return false;
	if ((day1.month == 2) && (day1.day == 29) && (day1.year % 4 != 0) || (!cin))
		return false;
	if ((day1.month == 2) && (day1.day == 29) && (day1.year % 400 == 0) && (cin))
		return true;
	if ((day1.month == 2) && (day1.day == 29) && (day1.year % 100 == 0) || (!cin))
		return false;
	if ((day1.month == 2) && (day1.day == 29) && (day1.year % 4 == 0) && (cin))
		return true;
	if ((day1.month == 2) && (day1.day > 29) || (!cin))
		return false;
	return true;
}

Date PreviousDay(Date day1)
{
	Date day2;

	if (((day1.year % 4) == 0) && (day1.month == 03) && (day1.day == 1)) 
	{ 
		day2.day = 29; 
		return day2;
	 }
	else
		if (((day1.year % 4) != 0) && (day1.month == 03) && (day1.day == 1)) 
		{
			day2.day = 28;
			return day2; 
		}
		else
			if ((day1.month == '01' || '02' || '04' || '06' || '08' || '09' || '11') && (day1.day == 1)) 
			{ 
				day2.day = 31; 
				return day2;
			}
			else 
				if ((day1.month == '05' || '07' || '10' || '12') && (day1.day == 1))
				{
					day2.day = 30;
					return day2;
				}
			else 
					day2.day = day1.day - 1;

	return day2;
}
