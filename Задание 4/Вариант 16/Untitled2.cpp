#include <iostream>
using namespace std;

int main(){
  int squareroot = 0;
  int number;
 setlocale(0,"");
  cout << "������� ����� ��� ���������� �����:" << endl;

  cin >> number;

  while (squareroot * squareroot != number){

      squareroot+=1;

}
cout << "������ ��������� �����:" << squareroot << endl;
return 0;
 }
