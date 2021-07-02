#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
    char a[300];
    char b[300];
    printf("First\n");
    scanf("%s", a);
    printf("Second\n");
    scanf("%s", b);
    int la = strlen(a);
    int lb = strlen(b);
    int l = la < lb ? lb + 2 : la + 2;
    char* c = new char[l];
    char* p = c + l - 1;
    int f = 0;
    for (--la, --lb, *p = 0; la >= 0 || lb >= 0; la--, lb--)
    {
        int ca = la >= 0 ? a[la] - '0' : 0;
        int cb = lb >= 0 ? b[lb] - '0' : 0;
        if ((ca != cb) || (cb != ca)) *--p = '1'; else *--p = '0';
        f = (ca + cb + f) / 10;
    }
    if (f) *--p = f + '0';
    cout << "result = " << p << endl;
    delete[] c;

    return 0;
}
