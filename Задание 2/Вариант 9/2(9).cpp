#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Date{
 private:
    int year;
    int month;
    int day;
 public:   
 
 string toString(){
     string s="";
     return to_string(year)+"г."+to_string(month)+"м."+to_string(day)+"д.";
 }
 
    Date(int _year,int _month,int _day){
       year=_year;
       month=_month;
       day=_day;
    }
    
    void addDay(){
        if(day<=30){
             day++; 
        }
      else{
          if(month!=12){
             day=1;
        month++; 
          }else{
              year++;
              day=1;
              month=1;
          }
          
      }
    }
};

int main()
{
    Date date = Date(2021,8,9);
    std::cout << date.toString() << std::endl;
    date.addDay();
    std::cout << date.toString() << std::endl;
    return 0;
}

