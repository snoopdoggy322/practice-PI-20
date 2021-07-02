#include <iostream>
using namespace std;
int main()
{
    struct time
    {
        int hour;
        int minutes;
        int seconds;
    };

    int n;
    time* times;
    n = 2;
    times = new time[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the hour for " << i + 1 << " time: ";
        cin >> times[i].hour;
        cout << endl;

        cout << "Enter the minutes for " << i + 1 << " date: ";
        cin >> times[i].minutes;
        cout << endl;

        cout << "Enter the seconds for " << i + 1 << " date: ";
        cin >> times[i].seconds;
        cout << endl;

    }

    for (int i = 0; i < n; i++)
    {
        if ((times[i].hour == times[i + 1].hour) && (times[i].minutes == times[i + 1].minutes) && (times[i].seconds == times[i + 1].seconds))
            cout << "Times are the same" << endl;
        else return 0;

    }
    return 0;
    system("pause");
}
