#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;



std::string readLine(){
    string s;
  cout<<"Введите строку : "<<endl;
  cin >> s;
  return s;
}

//Написать программу, которая считывает строку из консоли и определяет количество знаков 
//препинания каждого типа (. : ; ! ?,), выводит результат в консоль.
int main()
{ 
  system("chcp 1251");
  system("cls");
 string line = readLine();
 int count1=0;// .
 int count2=0;// :
 int count3=0;// ;
 int count4=0;// !
 int count5=0;// ?
 int count6=0;// ,

 for (char item : line){
        switch (item){
            case '.':
                count1++;
                break;
            
             case ':':
                count2++;
                break;
            
            case  ';':
                count3++;
                break;
            
            case  '!':
                count4++;
                break;
            
             case '?':
                count5++;
                break;
            
             case  ',':
                count6++;
                break;
            
        }
     
     
 }
    
    cout<<". - "<<count1<<endl;
    cout<<": -"<<count2<<endl;
    cout<<"; - "<<count3<<endl;
    cout<<"! - "<<count4<<endl;
    cout<<"? - "<<count5<<endl;
    cout<<", -"<<count6<<endl;
}




