#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;



//Написать программу, которая считывает строку из консоли и заменяет все символы - * 
//на случайный символ из списка - [_,=,+,#,@,^,&].

string readLine(){
    string s;
  cout<<"Введите строку : "<<endl;
  cin >> s;
  return s;
}

int main(){
    char listOfSpecSymbols [7] = {'_','=','+','#','@','^','&' }; 

    
    string line =readLine();
    string newLine="";
     for (char item : line){
         
         if(item == '*'){
             int randIndex=0 + rand() % 6;
         newLine+=listOfSpecSymbols[randIndex];    
         }
         else{
             newLine+=item;
         }
     }
     cout<<newLine;

    return 0;
}



