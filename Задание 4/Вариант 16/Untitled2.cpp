#include <iostream>
using namespace std;

int main(){
  int squareroot = 0;
  int number;
 setlocale(0,"");
  cout << "Введите число для вычисления корня:" << endl;

  cin >> number;

  while (squareroot * squareroot != number){

      squareroot+=1;

}
cout << "Корень заданного числа:" << squareroot << endl;
return 0;
 }
