#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>
 
using namespace std;


int complong(int lena, int lenb, int* a, int* b)
{
    if (lena < lenb)
        return -1;

    if (lena > lenb)
        return 1;

    for (int i = lena; i >= 1; i--) {
        if (a[i] < b[i])return -1;
        if (a[i] > b[i])return 1;
    }

    return 0;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int lena;
    lena = s1.length();
    int a[500];
    for (int i = 0; i < lena; i++)
        a[lena - i] = int(s1[i]) - 48;

    int lenb;
    lenb = s2.length();
    int b[500];
    for (int i = 0; i < lenb; i++)
        b[lenb - i] = int(s2[i]) - 48;

    int maxx = max(lena, lenb);
    if (maxx == lena)
        for (int i = lenb + 1; i <= lena; i++)
            b[i] = 0;

    else
        for (int i = lena + 1; i <= lenb; i++)
            a[i] = 0;

    if (complong(lena, lenb, a, b) < 0) {
        cout << "-";
        for (int i = 1; i <= maxx; ++i)
            swap(a[i], b[i]);
    }

    int c = 0;
    for (int i = 1; i <= maxx; ++i)
    {
        c = c + a[i] - b[i] + 10;
        a[i] = c % 10;
        if (c <= 9)c = -1;
        else c = 0;
    }


    while (a[maxx] == 0 && maxx > 1)
        maxx--;
    cout << "one number is greater than the other by: ";
    for (int i = maxx; i >= 1; i--)
        cout  << a[i];
}