#include <iostream>

using namespace std;

int main()
{
    struct date
    {
        int day;
        int month;
        int year;
    };

    int n;
    date* dates;
    n = 2;
    dates = new date[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the day for " << i + 1 << " date: ";
        cin >> dates[i].day;
        cout << endl;

        cout << "Enter the month for " << i + 1 << " date: ";
        cin >> dates[i].month;
        cout << endl;

        cout << "Enter the year for " << i + 1 << " date: ";
        cin >> dates[i].year;
        cout << endl;

    }

    for (int i = 0; i < n; i++)
    {

        if ((dates[i].day == dates[i + 1].day) && (dates[i].month == dates[i + 1].month) && (dates[i].year == dates[i + 1].year))
            cout << "Dates are the same" << endl;

        else return 0;

    }
    return 0;
    system("pause");
}
