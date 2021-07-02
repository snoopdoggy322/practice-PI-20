#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class DateTime{
 private:
    int year;
    int month;
    int day;
    int hour;
    int minutes;
    int seconds;
    
 public:
    DateTime(int _year,int _month,int _day,int _hour,int _minutes,int _seconds){
       year=_year;
       month=_month;
       day=_day;
       hour=_hour;
       minutes=_minutes;
       seconds=_seconds;
    }
    
    long differenceInSeconds(DateTime secondDate){
        return seconds+(minutes*60)+(hour*60*60)+(day*24*60*60)+(month*30*24*60*60)+(year*365*24*60*60);
    }

};
    int toDays(long s){
       return s/60/86839;
    }
int main()
{
     DateTime newYear = DateTime(2021,12,31,12,59,59);
    DateTime date = DateTime(2021,6,29,17,40,55);
     std::cout <<toDays(date.differenceInSeconds(newYear)) << std::endl;
    return 0;
}
