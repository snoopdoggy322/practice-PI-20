#include <iostream>
#include <string>

using namespace std;

const int RANK = 500; //Шаг 1.

string FromDecimalToAdditionalBinary(string, int); //суп

bool ifDecimalValid(string); //суп
string SumBinary(string, string, int);

int main()
{
    string Znach1; //Шаг 2.
    setlocale(LC_ALL, "Russian");

    while (true)
    {
        cout << "a=";
        cin >> Znach1; //Шаг 3.
        if (!(ifDecimalValid(Znach1))) { cout << "vvedite celoe chislo!" << endl; continue; } //Шаг 4.
        Znach1 = FromDecimalToAdditionalBinary(Znach1, RANK);   //Шаг 5.
        if (Znach1 == "ERROR") { cout << "ДBolshe" << RANK << " rasrjadov!" << endl; continue; } //Шаг 6.
        break;
    }
    cout << "a v dopoln. kode " << Znach1 << endl; //Шаг 7.
    system("Pause");
    return 0;
}

string FromDecimalToAdditionalBinary(string value, int RANK)
{
    bool flag = false;
    if (value[0] == '-') { flag = true; value.erase(0, 1); }
    string Binary; int Decimal = 0;
    for (int i = value.length() - 1, grade = 1; i > -1; i--, grade *= 10)
    {
        Decimal = Decimal + (value[i] - '0') * grade;
    }
    for (; Decimal != 0; Decimal /= 2) { Binary = char((Decimal % 2) + '0') + Binary; }

    if (Binary.length() > RANK) { return "ERROR"; }

    for (int i = Binary.length(); i < RANK; i++) { Binary = '0' + Binary; }

    if (flag)
    {
        for (int i = RANK - 1; i > 0; i--)
        {
            if (Binary[i] == '1') { Binary[i] = '0'; }
            else { Binary[i] = '1'; }
        }
        Binary[0] = '1';
        Binary = SumBinary(Binary, FromDecimalToAdditionalBinary("1", RANK), RANK);
    }

    return Binary;
}


bool ifDecimalValid(string value)
{
    for (int i = value.length() - 1; i > -1; i--)
    {
        if (!(((value[i] >= '0') && (value[i] <= '9')) ||
            ((value[i] == '-') && (i == 0)) && (value.length() != 1))) {
            return false;
        }
    }
    return true;
}

string SumBinary(string v1, string v2, int RANK)
{
    string Sum, some, flag = "0";
    for (int i = RANK - 1; i > -1; i--)
    {
        some = string(flag) + v1[i] + v2[i];
        if ((some == "010") || (some == "001") || (some == "100")) { Sum = '1' + Sum; flag = '0'; continue; }
        if ((some == "011") || (some == "101") || (some == "110")) { Sum = '0' + Sum; flag = '1'; continue; }
        if (some == "111") { Sum = '1' + Sum; flag = '1'; continue; }
        if (some == "000") { Sum = '0' + Sum; flag = '0'; continue; }
    }
    if (flag == "1") { return "ERROR"; }
    return Sum;
}