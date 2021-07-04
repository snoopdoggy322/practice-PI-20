#include <iostream>
#include <string.h>

using namespace std;

int CatValue(int ValFirst, int ValSecond)
{
    ValFirst = ValFirst * 10 + ValSecond;
    return ValFirst;
}


void MulFive(string str, unsigned int* mas_div, unsigned int* mas_answer)
{
    int length = str.length();          //����� ������
    int remainder = 0, value = 0;       //������� � �������� ��� �������������� �������
    for (int i = 0; i < length; i++)    //������������� �������, ���� ����� ������ ���� � ������ ���� int
    {
        mas_div[i] = (int)str[i] - 48;
    }
    {
    }
    int j = 0;
    value = mas_div[0] / 2;         //����� ������ �����
    mas_answer[j] = value;
    remainder = mas_div[0] % 2;     //������� ��������� ������� ������ �����
    j++;
    for (int i = 1; i < length; i++)
    {
        value = CatValue(remainder, mas_div[i]) / 2;
        mas_answer[j] = value;
        remainder = mas_div[i] % 2;
        j++;
    }
    cout << "\t�����: ";
    for (int j = 0; j < length; j++)    //����� ������� � �������
    {
        cout << mas_answer[j];
    }
}


//���������� ������� ���������
int main()
{
    unsigned int* mas_div, * mas_answer;
    string str;
    cout << "\n\t������� �����: ";
    cin >> str;
    mas_div = (unsigned int*)calloc(str.length(), sizeof(unsigned int));       //��������� ������ calloc
    mas_answer = (unsigned int*)calloc(str.length(), sizeof(unsigned int));
    MulFive(str, mas_div, mas_answer);
    int remainder = (int)str.back() - 48;
    cout << remainder % 2 ? '0' : '5';
    return 0;
}